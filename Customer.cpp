// Customer.cc
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

std::string Customer::statement()
{
  // 프라이빗 멤버로 잡아도 될 것 같은데..
  double totalAmount = 0.;
  int frequentRenterPoints = 0;

  // 반복문 안에 바로 써도 되지 않을까
  std::vector< Rental >::iterator iter = m_customerRentals.begin();
  std::vector< Rental >::iterator iter_end = m_customerRentals.end();

  // 최종 내역만 출력하는 함수로 빼도 괜찮아보임
  // result will be returned by statement()
  std::ostringstream result;
  result << "Rental Record for " << getName() << "\n";

  // Loop over customer's rentals
  for ( ; iter != iter_end; ++iter ) {

    double thisAmount = 0.;
    Rental each = *iter;

    // 대여 기간 별로 가격을 출력하는 함수로 빼도 괜찮아보임
    // 새로운 장르도 추가하고
    // Determine amounts for each rental
    switch ( each.getMovie().getPriceCode() ) {

      case Movie::REGULAR:
        thisAmount += 2.;
        if ( each.getDaysRented() > 2 )
          thisAmount += ( each.getDaysRented() - 2 ) * 1.5 ;
        break;

      case Movie::NEW_RELEASE:
        thisAmount += each.getDaysRented() * 3;
        break;

      case Movie::CHILDRENS:
        thisAmount += 1.5;
        if ( each.getDaysRented() > 3 )
          thisAmount += ( each.getDaysRented() - 3 ) * 1.5;
        break;
    }

    // Add frequent renter points
    frequentRenterPoints++;

    // Add bonus for a two day new release rental
    if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
         && each.getDaysRented() > 1 ) frequentRenterPoints++;

    // Show figures for this rental
    result << "\t" << each.getMovie().getTitle() << "\t"
           << thisAmount << std::endl;
    totalAmount += thisAmount;
  }

  // Add footer lines
  result << "Amount owed is " << totalAmount << "\n";
  result << "You earned " << frequentRenterPoints
         << " frequent renter points";

  return result.str();
}

std::string Customer::newStatement()
{
    std::ostringstream result;
    result << "Rental Record for " << getName() << "\n";

    // 장르 제목 대여기간 가격
    const int size = m_customerRentals.size();

    for (int i = 0; i < size; ++i)
    {
        auto title_ = m_customerRentals[i].getMovie().getTitle();
        auto genre_ = m_customerRentals[i].getMovie().getPriceCode();
        auto daysRented_ = m_customerRentals[i].getDaysRented();
        auto amount_ = getAmount(genre_, daysRented_);
        
        // Show figures for this rental
        result << "\t" << m_customerRentals[i].getMovie().getGenreString(genre_) << "\t" << title_ << "\t"
            << daysRented_ << "\t" << amount_ << std::endl;
    }

    return result.str();
}

double Customer::getAmount(int code, int dayRented)
{
    double thisAmount = 0.;

    switch (code) {

    case Movie::REGULAR:
        thisAmount += 2.;
        if (dayRented > 2)
            thisAmount += (dayRented - 2) * 1.5;
        break;

    case Movie::NEW_RELEASE:
        thisAmount += dayRented * 3;
        break;

    case Movie::CHILDRENS:
        thisAmount += 1.5;
        if (dayRented > 3)
            thisAmount += (dayRented - 3) * 1.5;
        break;

    case Movie::EXAMPLE_GENRE:
        thisAmount += 2.5;
        if (dayRented > 2)
            thisAmount += (dayRented - 1) * 1.5;
        break;
    }

    return thisAmount;
}
