#pragma once



#ifdef CPPLIBRARY_EXPORTS
#define CPPLIBRARY __declspec(dllexport)
#else
#define CPPLIBRARY __declspec(dllimport)
#endif

/* Funkcja odpowiadajaca za  zmienianie kontrastu bitmapy napisana w jezyku wysokiego poziomu
* @param buf bufor pikseli RGB
* @param part czesc bitmapy
* @param start poczatek indeksu
* @param end koniec indeksu
* @param factor wspolczynnik poprawy kontrastu 
*/
extern "C" CPPLIBRARY void cppAlg(unsigned char* buf, unsigned char* part, int start, int end, float factor);