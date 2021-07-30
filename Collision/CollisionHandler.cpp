#include "CollisionHandler.h"
#include "MapParser.h"

CollisionHandler* CollisionHandler::s_Instance = nullptr;

CollisionHandler::CollisionHandler()
{
    m_CollisionLayer = (TileLayer*)MapParser::GetInstance()->GetMaps("map")->GetMapLayers().front();
    m_CollisionTileMap = m_CollisionLayer->GetTileMap();
}


bool CollisionHandler::CheckCollision(SDL_Rect a, SDL_Rect b)
{
    bool x_overlaps = (a.x < b.x + b.w) && (a.x + a.w > b.x);
    bool y_overlaps = (a.y < b.y + b.h) && (a.y + a.h > b.y);
    return (x_overlaps && y_overlaps);
}

bool CollisionHandler::CheckPointInsideBox(Point point, SDL_Rect box)
{
    return (( point.X > box.x ) && ( point.X < box.x + box.w ) && ( point.Y > box.y ) && ( point.Y  < box.y + box.h ) );
}

bool CollisionHandler::MapCollision(SDL_Rect a)
{
    int tileSize = 32;
    int RowCount = 20;
    int ColCount = 50;

    int left_tile = a.x / tileSize;
    int right_tile = (a.x + a.w) / tileSize;

    int top_tile = a.y / tileSize;
    int bottom_tile = (a.y + a.h) / tileSize;

    if(left_tile < 0) left_tile = 0;
    if(right_tile > ColCount) right_tile = ColCount;

    if(top_tile < 0) top_tile = 0;
    if(bottom_tile > RowCount) bottom_tile = RowCount;

    for(int i = left_tile; i <= right_tile; ++i)
    {
        for(int j = top_tile; j <= bottom_tile; ++j)
        {
            if(m_CollisionTileMap[j][i] > 0)
            {
                return true;
            }
        }
    }

    return false;
}
