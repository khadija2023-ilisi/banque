#pragma once
#include "Devise.h"
namespace banque {
    class Dollar :
        public Devise
    {
    public:
        Dollar(double val);
        Dollar* convertToDollar();
        MAD* convertToMad();
        Euro* convertToEuro();
        void afficher()const;
    private:
        static float T_MAD;
        static float T_Euro;
    };
};


