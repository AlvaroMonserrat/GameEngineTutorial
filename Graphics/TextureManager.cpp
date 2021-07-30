#include "TextureManager.h"
#include "Engine.h"
#include "TextureManager.h"
#include "Camera.h"
#include "tinyxml.h"
#include <iostream>

TextureManager* TextureManager::s_Instance = nullptr;

bool TextureManager::Load(std::string id, std::string filename)
{
    SDL_Texture* newTexture = nullptr;

    //Cargar la imagen desde una ruta especifica
    SDL_Surface* loadedSurface = IMG_Load(filename.c_str());

    if(loadedSurface == nullptr)
    {
        SDL_Log("Error al cargar la imagen en la ruta: %s\n", filename.c_str());
    }
    else
    {
        //Color key image
        //SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        newTexture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), loadedSurface);

        if(newTexture == nullptr)
        {
            SDL_Log("Error al crear texture: %s\n", SDL_GetError());
        }


        SDL_FreeSurface(loadedSurface);
    }

    m_TextureMap[id] = newTexture;

    return m_TextureMap[id] != nullptr;

}

bool TextureManager::ParseTexture(std::string source)
{
    TiXmlDocument xml;
    xml.LoadFile(source);

    if(xml.Error())
    {
        std::cout << "Failed to load " << source << std::endl;
        return false;
    }

    TiXmlElement* root = xml.RootElement();
    for(TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        if(e->Value() == std::string("texture"))
        {
            std::string id = e->Attribute("id");
            std::string src = e->Attribute("source");

            std::cout << "id:" << id << std::endl;
            std::cout << "src:" << src << std::endl;
            if(!Load(id, src))
                return false;
        }

    }
    return true;
}

void TextureManager::Drop(std::string id)
{
    SDL_DestroyTexture(m_TextureMap[id]);
    m_TextureMap.erase(id);
}

void TextureManager::Clean()
{
    std::map<std::string, SDL_Texture*>::iterator it;

    for(it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
        SDL_DestroyTexture(it->second);

    m_TextureMap.clear();

    SDL_Log("Texture map cleaned!");

}

void TextureManager::DrawWidget(std::string id, int x, int y, int width, int height,float scaleXY, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {0, 0, width/scaleXY, height/scaleXY};

    //SDL_Rect dstRect = {PackManager::->GetInstance()->GetPositionX(id), PackManager::->GetInstance()->GetPositionY(id)};
    //std::cout << "width:" << width << std::endl;
    SDL_Rect dstRect = {x, y, width, height};

    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, float scaleX, float scaleY, float scrollRatio, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {0, 0, width, height};

    Vector2D cam = Camera::GetInstance()->GetPosition() * scrollRatio;

    SDL_Rect dstRect = {x - cam.X, y - cam.Y, width*scaleX, height*scaleY};

    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &dstRect, 0, nullptr, flip);

}


void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip)
{

    SDL_Rect srcRect = {width*frame, height*(row), width, height};
    Vector2D cam = Camera::GetInstance()->GetPosition();


    SDL_Rect dstRect = {x - cam.X, y - cam.Y, width, height};

    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &dstRect, 0, nullptr, flip);

}


void TextureManager::DrawTile(std::string tilesetID, int tileSize, int x, int y, int row, int frame, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {tileSize*frame, tileSize*(row), tileSize, tileSize};
    Vector2D cam = Camera::GetInstance()->GetPosition();

    SDL_Rect dstRect = {x - cam.X, y - cam.Y, tileSize, tileSize};

    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[tilesetID], &srcRect, &dstRect, 0, 0, flip);

}
