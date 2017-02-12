//
//  Utility.h
//  GameV2
//
//  Created by PAN on 16/5/1.
//  Copyright © 2016年 Eason. All rights reserved.
//


// ----------- CLASSES
class Utilities
{
private:
    
public:
    static double distance(int x1, int y1, int x2, int y2)
    {
        double distance = 0;
        
        distance = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
        
        return distance;
    }
    
    
};