#pragma once
#include "Devise.h"
namespace banque {
    class Euro :
        public Devise
    {
    public:
        Euro(double val);
        Dollar* convertToDollar();
        MAD* convertToMad();
        Euro* convertToEuro();
        void afficher()const;
    private:
        static float T_Dollar;
        static float T_MAD;
    };
};


