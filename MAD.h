#pragma once
#include "Devise.h"
namespace banque {
    class MAD :
        public Devise
    {
    public:
        MAD(double val);
         Dollar* convertToDollar();
         MAD* convertToMad();
         Euro* convertToEuro();
         void afficher()const;
    private:
        static float T_Dollar;
        static float T_Euro;
    };
};


