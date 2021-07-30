#include "Button.h"
#include "tinyxml.h"

Button::Button(std::string widgetID, int x, int y, int width, int height, float scale)
{
    //Cargar ID texture
    Parse(widgetID, "assets/widgets.aml");
    m_ButtonPressed = false;
    m_WidgetID = widgetID;
    m_TextureID = m_MapTextureID[NORMAL];
    m_Scale = scale;
    m_Box = {x, y, width*m_Scale, height*m_Scale};
    //m_Box.x = (960 / 2)-((m_Box.w)/2);
    //m_Box.y = (640 / 2) - ((m_Box.h) / 2);
}

void Button::Draw()
{
    TextureManager::GetInstance()->DrawWidget(m_TextureID, m_Box.x, m_Box.y, m_Box.w, m_Box.h, m_Scale, SDL_FLIP_NONE);
}

void Button::Update()
{
    Point mouseXY = Input::GetInstance()->GetPoint();
    //If the mouse is over the button
    if(CollisionHandler::GetInstance()->CheckPointInsideBox(mouseXY, m_Box))
    {
        m_TextureID = m_MapTextureID[HOOKOVER];

        if(Input::GetInstance()->GetMousePressLeft())
        {
            m_TextureID = m_MapTextureID[PRESSED];
            m_ButtonPressed = true;
        }
        else
        {
            m_ButtonPressed = false;
        }
    }else
    {
        m_TextureID = m_MapTextureID[NORMAL];
    }

}

bool Button::isClicked()
{
    return m_ButtonPressed;
}

void Button::Parse(std::string widgetID, std::string source)
{
    TiXmlDocument xml;
    xml.LoadFile(source);

    if(xml.Error())
    {
        std::cout << "Failed to load animation file: " << source << std::endl;
    }

    TiXmlElement* root = xml.RootElement();
    for(TiXmlElement* e = root->FirstChildElement(); e!=nullptr; e=e->NextSiblingElement())
    {
        if(e->Value() == std::string("button"))
        {
            std::string id = e->Attribute("id");

            if(id.compare(widgetID) == 0)
            {
                int i = 0;
                for(TiXmlElement* state=e->FirstChildElement(); state!=nullptr; state=state->NextSiblingElement())
                {
                    m_MapTextureID.insert(std::pair<int, std::string>(i, state->Attribute("textureID")));
                    i++;
                }
            }

            //  std::cout << m_MapTextureID[NORMAL] << std::endl;
            //  std::cout << m_MapTextureID[HOOKOVER] << std::endl;
            //  std::cout << m_MapTextureID[PRESSED] << std::endl;
        }

    }
}

void Button::Clean()
{

}
