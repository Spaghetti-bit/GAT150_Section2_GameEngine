#include "pch.h"
#include "Transform.h"

namespace nc
{
    std::istream& operator>>(std::istream& stream, Transform& t)
    {
        
        stream >> t.position;

        std::string line;


        std::getline(stream, line);
        t.scale = stof(line);

        std::getline(stream, line);
        t.angle = stof(line);

       /* stream >> t.scale;
        stream >> t.angle;*/

        

        return stream;
    }

}
