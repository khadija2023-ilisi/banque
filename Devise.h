#pragma once
namespace banque {
	class Dollar;
	class Euro;
	class MAD;
	class Devise
	{
		double valeur;
	public:
		Devise(double);
		Devise& operator+(const Devise& M) const;
		Devise& operator-(const Devise& M) const;
		Devise& operator*(const Devise& M) const;
		void operator*(double d); 
		bool operator<=(const Devise& M)const;
		bool operator>=(const Devise& M)const;
		double convert(double taux);
		virtual Dollar* convertToDollar();
		virtual MAD* convertToMad();
		virtual Euro* convertToEuro();
		virtual void afficher()const;
		int return_type();
	};
};


