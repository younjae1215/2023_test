// Rental.hh
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
  Rental( const Movie& movie, int daysRented );

  int getDaysRented() const;
  const Movie& getMovie() const;

  // 가격은 rental에 있어야 더 맞는거 같아보임
  float getAmount(int genre, int daysRented) {
      float thisAmount = 0.;

      switch (genre) {

      case Movie::REGULAR:
          thisAmount += 2.;
          if (daysRented > 2)
              thisAmount += (daysRented - 2) * 1.5;
          break;

      case Movie::NEW_RELEASE:
          thisAmount += daysRented * 3;
          break;

      case Movie::CHILDRENS:
          thisAmount += 1.5;
          if (daysRented > 3)
              thisAmount += (daysRented - 3) * 1.5;
          break;

      case Movie::EXAMPLE_GENRE:
          thisAmount += 2.5;
          if (daysRented > 2)
              thisAmount += (daysRented - 1) * 1.5;
          break;
      }

      return thisAmount;
  }

private:
  Movie m_rentedMovie;
  int m_nDaysRented;
};

inline Rental::Rental( const Movie& movie, const int daysRented ):
	m_rentedMovie( movie ),
	m_nDaysRented( daysRented ) {}

inline int Rental::getDaysRented() const { return m_nDaysRented; }

inline const Movie& Rental::getMovie() const { return m_rentedMovie; }

#endif // RENTAL_H
