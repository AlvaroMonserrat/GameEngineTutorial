#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "Widget.h"
#include "TextureManager.h"
#include "CollisionHandler.h"
#include "Input.h"
#include "Point.h"

enum{
    NORMAL,
    HOOKOVER,
    PRESSED
};

class Button : public Widget
{
    public:
        Button(std::string widgetID, int x, int y, int width, int height, float scaleXY=1);
        //Button(std::string widgetID, int x, int y, int width, int height, float scaleXY=1, Parameters parameters);
        virtual void Draw();
        virtual void Update();
        virtual void Clean();
        virtual bool isClicked();

        void Parse(std::string widgetID, std::string source);


    private:
        //Contiene nombre generico de los estados del boton y el ID único de la textura
        std::map<int, std::string> m_MapTextureID;
        std::string m_WidgetID;
        std::string m_TextureID;
        bool m_ButtonPressed = false;
        float m_Scale=1;
};

#endif // BUTTON_H
