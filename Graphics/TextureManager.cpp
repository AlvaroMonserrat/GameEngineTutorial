#include "TextureManager.h"
#include "Engine.h"
TextureManager::TextureManager()
{

}

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

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {0, 0, width, height};

    SDL_Rect dstRect = {x, y, width, height};

    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &dstRect, 0, nullptr, flip);

}

void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {width*frame, height*(row-1), width, height};

    SDL_Rect dstRect = {x, y, width, height};

    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &dstRect, 0, nullptr, flip);

}

