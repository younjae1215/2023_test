// Rental.hh
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
  Rental( const Movie& movie, int daysRented );

  int getDaysRented() const;
  const Movie& getMovie() const;

private:
  Movie m_rentedMovie;
  int m_nDaysRented;
};

// daysRented는 왜 const가 아닐까
inline Rental::Rental( const Movie& movie, int daysRented ):
	m_rentedMovie( movie ),
	m_nDaysRented( daysRented ) {}

inline int Rental::getDaysRented() const { return m_nDaysRented; }

inline const Movie& Rental::getMovie() const { return m_rentedMovie; }

#endif // RENTAL_H
