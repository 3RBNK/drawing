//
// Created by bnkr on 25.10.2024.
//

#ifndef REFLECTABLE_H
#define REFLECTABLE_H

class reflectable { // Фигуры, пригодные к зеркальному отражению
public:
    virtual void flipHorisontally() = 0;
    virtual void flipVertically() = 0;
};

#endif //REFLECTABLE_H
