#include "Number.h"

int LungimeSir(const char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return i;
}
void strcpy(char* a,const char* b)
{
	int i = 0;
	while (b[i] != '\0')
	{
		a[i] = b[i];
		i++;
	}
	a[i] = '\0';
}
Number::Number(const char* value, int base)
{
	this->lungime = LungimeSir(value);

	this->valoare = new char[this->lungime + 1];

	strcpy(this->valoare, value);

	this->baza = base;
	
}

int Number::GetDigitsCount()
{
	return this->lungime;
}
int Number::GetBase()
{
	return this->baza;
}

void Number::Print()
{
	printf("%s %d \n", this->valoare, this->baza);
}
int ConvertToNumber(const char* s)
{
	int nr = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		nr = nr * 10 + (s[i] - '0');
	}
	return nr;
}

int Convert(const char*s,int base)//din 11-16 in 10;
{  
	int numar = 0, p = 1;;
	int n = LungimeSir(s);

	for(int i=n-1;i>=0;i--)
	{
		if ( s[i] >= '0' && s[i]<= '9')
			numar = numar + (s[i]-'0') * p;
		else if (s[i] >= 'A' && s[i] <= 'F')
			numar = numar + (int(s[i]) - int('A') + 10) * p;

		p = p * base;
	}
	return numar;
}
void InversareSir(char s[100])
{
	int n = LungimeSir(s);//inversare sir;
	for (int i = 0; i < n / 2; i++)
	{
		char aux = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = aux;
	}
}
char *ConvertToHigher(int nr, int base)//din 10 in 11-16
{
	char a[100];
	int i = 0;
	while (nr != 0)
	{
		int c = nr % base;
		if (c < 10)
			a[i++] = c + '0';
		else if (c >= 10)
			a[i++] = char(c - 10 + int('A'));
		nr = nr / base;

	}
	a[i++] = '\0';
	InversareSir(a);
	return a;
}
int ConvertToLower(int nr, int base)//din baza 10 in 2-9
{
	int p = 1, c, numar = 0;

	while (nr != 0)
	{
		c = nr % base;
		nr = nr / base;
		numar = p * c + numar;
		p *= 10;
	}
	return numar;
}
int ConvertBase10(int nr,int base)//de la 2-9 la 10
{
	int s = 0, p = 1;
	while (nr != 0)
	{
		int c = nr % 10;
		nr = nr / 10;
		s = s + c * p;
		p = p * base;
	}
	return s;
}

char *NumberToSir(int numar)
{
	char val[100];
	int i = 0;

	while (numar != 0)///creare sir 
	{
		int c = numar % 10;
		val[i++] = c + '0';
		numar = numar / 10;
	}
	val[i++] = '\0';
	return val;
}
void Number::SwitchBase(int newbase)
{
	int nr = ConvertToNumber(this->valoare);
	int numar;
	char valoare[100] = { 0 };

	if (this->baza <= 10 && newbase <= 10)
	{
		nr = ConvertBase10(nr, this->baza);
		numar = ConvertToLower(nr, newbase);
		strcpy(valoare,NumberToSir(numar));
		InversareSir(valoare);
	}
	else if (this->baza > 10 && newbase > 10)
	{
		nr = Convert(this->valoare, this->baza);
        strcpy(valoare,ConvertToHigher(nr, newbase));
	}
	else if (this->baza <= 10 && newbase > 10)
	{
		nr = ConvertBase10(nr, this->baza);
	    strcpy(valoare,ConvertToHigher(nr, newbase));

	}
	else if (this->baza > 10 && newbase <= 10)
	{
		nr = Convert(this->valoare, this->baza);
		numar = ConvertToLower(nr, newbase);
		strcpy(valoare,NumberToSir(numar));
		InversareSir(valoare);
	}

	this->baza = newbase;
	strcpy(this->valoare,valoare);
	this->lungime = LungimeSir(valoare);
}
int BazaMaxima(int a,int b)
{
	int max;
	if (a > b)
		max = a;
	else
		max = b;
	return max;
}
Number  operator+(Number a,Number b)
{
	
	int val1, val2;
	char newvalue[101] ;

	if (b.baza > 10)
		val1 = Convert(b.valoare,b.baza);
	if (b.baza <= 10)
	{
		val1 = ConvertToNumber(b.valoare);
		val1 = ConvertBase10(val1,b.baza);
	}

	if (a.baza > 10)
		val2 = Convert(a.valoare, a.baza);
	if (a.baza <= 10)
	{
		val2 = ConvertToNumber(a.valoare);
		val2 = ConvertBase10(val2, a.baza);
	}
	int suma = val1 + val2;

	strcpy(newvalue, NumberToSir(suma));

	InversareSir(newvalue);

	Number d(newvalue, 10);

	int max = BazaMaxima(a.baza, b.baza);

	d.SwitchBase(max);

	return d;
	
}
Number operator-(Number m, Number n)
{
	int num1, num2;
	char value[101] = { 0 };

	if (m.baza > 10)
		num1 = Convert(m.valoare,m.baza);
	else if (m.baza <= 10)
	{
		num1 = ConvertToNumber(m.valoare);
		num1 = ConvertBase10(num1, m.baza);
	}

	if (n.baza > 10)
		num2 = Convert(n.valoare, n.baza);
	else if (n.baza <= 10)
	{
		num2 = ConvertToNumber(n.valoare);
		num2 = ConvertBase10(num2,n.baza);
	}
	int dif=0;

	if (num1 > num2)
		dif = num1 - num2;
	else
		dif = num2 - num1;

	strcpy(value, NumberToSir(dif));
	InversareSir(value);

	int max = BazaMaxima(m.baza, n.baza);
	Number a (value, 10);
	a.SwitchBase(max);

	return a;
}

int Number:: operator>(Number b)
{
	int val1, val2;
	
	if (this->baza > 10)
		val1 = Convert(this->valoare, this->baza);
	else if (this->baza <= 10)
	{
		val1 = ConvertToNumber(this->valoare);
		val1 = ConvertBase10(val1, this->baza);
	}

	if (b.baza > 10)
		val2 = Convert(b.valoare, b.baza);
	else if (b.baza <= 10)
	{
		val2 = ConvertToNumber(b.valoare);
		val2 = ConvertBase10(val1, b.baza);
	}
	if (val1 > val2)
		return 1;
	
	return 0;
}

int Number::operator<(Number x)
{
	int val1, val2;

	if (this->baza > 10)
		val1 = Convert(this->valoare,this->baza);
	else if (this->baza <= 10)
	{
		val1 = ConvertToNumber(this->valoare);
		val1 = ConvertBase10(val1, this->baza);
	}

	if (x.baza > 10)
		val2 = Convert(x.valoare, x.baza);
	else if (x.baza <= 10)
	{
		val2 = ConvertToNumber(x.valoare);
		val2 = ConvertBase10(val2, x.baza);
	}

	if (val1 < val2)
		return 1;
	
	return 0;
}
int Number:: operator<=(Number z)
{
	int val1, val2;

	if (this->baza > 10)
		val1 = Convert(this->valoare, this->baza);
	else if (this->baza <= 10)
	{
		val1 = ConvertToNumber(this->valoare);
		val1 = ConvertBase10(val1, this->baza);
	}

	if (z.baza > 10)
		val2 = Convert(z.valoare, z.baza);
	else if (z.baza <= 10)
	{
		val2 = ConvertToNumber(z.valoare);
		val2 = ConvertBase10(val2, z.baza);
	}

	if (val1 <= val2)
		   return 1;

	return 0;
}
int Number::operator>=(Number m)
{
	int val1, val2;

	if (this->baza > 10)
		val1 = Convert(this->valoare, this->baza);
	else if (this->baza <= 10)
	{
		val1 = ConvertToNumber(this->valoare);
		val1 = ConvertBase10(val1, this->baza);
	}

	if (m.baza > 10)
		val2 = Convert(m.valoare, m.baza);
	else if (m.baza <= 10)
	{
		val2 = ConvertToNumber(m.valoare);
		val2 = ConvertBase10(val2, m.baza);
	}

	if (val1 >= val2)
		return 1;

	return 0;
 }
int Number:: operator==(Number a)
{
	int val1, val2;

	if (this->baza > 10)
		val1 = Convert(this->valoare, this->baza);
	else if (this->baza <= 10)
	{
		val1 = ConvertToNumber(this->valoare);
		val1 = ConvertBase10(val1, this->baza);
	}

	if (a.baza > 10)
		val2 = Convert(a.valoare, a.baza);
	else if (a.baza <= 10)
	{
		val2 = ConvertToNumber(a.valoare);
		val2 = ConvertBase10(val2,a.baza);
	}
	if (val1 == val2)
		return 1;

	return 0;
}
int Number:: operator!=(Number b)
{
	int val1, val2;

	if (this->baza > 10)
		val1 = Convert(this->valoare, this->baza);
	else if (this->baza <= 10)
	{
		val1 = ConvertToNumber(this->valoare);
		val1 = ConvertBase10(val1, this->baza);
	}

	if (b.baza <= 10)
		val2 = Convert(b.valoare, b.baza);
	else if (b.baza <= 10)
	{
		val2 = ConvertToNumber(b.valoare);
		val2 = ConvertBase10(val2, b.baza);
	}
	if (val1 != val2)
		return 1;

	return 0;
}
char Number::operator[](int n)
{
	return valoare[n];
}

Number& Number:: operator=(Number a)
{
	this->valoare = a.valoare;
	this->baza = a.baza;
	this->lungime = a.lungime;

	return(*this);
}
Number& Number::operator=(const char* s)
{   
	strcpy(this->valoare, s);
	this->lungime = LungimeSir(this->valoare);
	return (*this);
}
Number& Number:: operator=(int m)
{

	char val[101];
	int numar;

	if (this->baza > 10)
		strcpy(val, ConvertToHigher(m, this->baza));
	else if (this->baza <= 10)
	{
		numar = ConvertToLower(m, this->baza);
		strcpy(val, NumberToSir(numar));
		InversareSir(val);
	}
	
	strcpy(this->valoare, val);
	this->lungime = LungimeSir(this->valoare);
	return (*this);

}
Number& Number:: operator+=(Number c)
{ 
	int val1, val2;

	if (this->baza > 10)
		val1 = Convert(this->valoare, this->baza);
	else if (this->baza <= 10)
	{
		 val1 = ConvertToNumber(this->valoare);
		 val1 = ConvertBase10(val1, this->baza);
	}

	if (c.baza > 10)
		val2 = Convert(c.valoare, c.baza);
	else if (c.baza <= 10)
	{
		val2 = ConvertToNumber(c.valoare);
		val2 = ConvertBase10(val2, c.baza);
	}
	int suma = val1 + val2;

	char a[101];
	int max = BazaMaxima(this->baza, c.baza);
	if (max > 10)
		strcpy(a, ConvertToHigher(suma, max));
	else if (max <= 10)
	{
		suma = ConvertToLower(suma,max);
		strcpy(a, NumberToSir(suma));
		InversareSir(a);
	}
	strcpy(this->valoare, a);

	return (*this);


}
Number::Number(int x)
{
	char a[101];
	strcpy(a, NumberToSir(x));
	InversareSir(a);

	this->lungime = LungimeSir(a);
	this->valoare = new char[this->lungime + 1];
	this->baza = 10;
	strcpy(this->valoare, a);
}
Number& Number:: operator--()
{
	strcpy(this->valoare + 0, this->valoare + 1);

	return (*this);
}
Number& Number::operator--(int x)
{
	int n = this->lungime;
	strcpy(this->valoare + n - 1, this->valoare + n );

	return (*this);
}
Number::Number(Number&d)
{
	this->valoare = d.valoare;
	this->baza = d.baza;
	this->lungime = d.lungime;
}
Number::Number(Number&& e)
{
	char* temp = e.valoare;
	e.valoare = nullptr;
	this->valoare = temp;
}
Number::~Number()
{
	valoare = nullptr;
	delete valoare;
}