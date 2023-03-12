// Customer.cc
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

//std::string Customer::statement()
//{
//  // 프라이빗 멤버로 잡아도 될 것 같은데..
//  double totalAmount = 0.;
//  int frequentRenterPoints = 0;
//
//  // 반복문 안에 바로 써도 되지 않을까
//  std::vector< Rental >::iterator iter = m_customerRentals.begin();
//  std::vector< Rental >::iterator iter_end = m_customerRentals.end();
//
//  // 최종 내역만 출력하는 함수로 빼도 괜찮아보임
//  // result will be returned by statement()
//  std::ostringstream result;
//  result << "Rental Record for " << getName() << "\n";
//
//  // Loop over customer's rentals
//  for ( ; iter != iter_end; ++iter ) {
//
//    double thisAmount = 0.;
//    Rental each = *iter;
//
//    // 대여 기간 별로 가격을 출력하는 함수로 빼도 괜찮아보임
//    // 새로운 장르도 추가하고
//    // Determine amounts for each rental
//    switch ( each.getMovie().getPriceCode() ) {
//
//      case Movie::REGULAR:
//        thisAmount += 2.;
//        if ( each.getDaysRented() > 2 )
//          thisAmount += ( each.getDaysRented() - 2 ) * 1.5 ;
//        break;
//
//      case Movie::NEW_RELEASE:
//        thisAmount += each.getDaysRented() * 3;
//        break;
//
//      case Movie::CHILDRENS:
//        thisAmount += 1.5;
//        if ( each.getDaysRented() > 3 )
//          thisAmount += ( each.getDaysRented() - 3 ) * 1.5;
//        break;
//    }
//
//    // Add frequent renter points
//    frequentRenterPoints++;
//
//    // Add bonus for a two day new release rental
//    if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
//         && each.getDaysRented() > 1 ) frequentRenterPoints++;
//
//    // Show figures for this rental
//    result << "\t" << each.getMovie().getTitle() << "\t"
//           << thisAmount << std::endl;
//    totalAmount += thisAmount;
//  }
//
//  // Add footer lines
//  result << "Amount owed is " << totalAmount << "\n";
//  result << "You earned " << frequentRenterPoints
//         << " frequent renter points";
//
//  result << std::endl << newStatement() << std::endl;
//
//  return result.str();
//}

std::string Customer::statement_()
{
    updateCustomerData();
    return printReceipt();
}

void Customer::updateCustomerData()
{
    // Loop over customer's rentals
    for (auto each : m_customerRentals)
    {
        auto genre_ = each.getMovie().getGenre();
        auto daysRented_ = each.getDaysRented();
        auto thisAmount = getAmount(genre_, daysRented_);
        m_totalAmount.emplace_back(thisAmount);
 
        // Add frequent renter points
        m_renterPoint++;

        // Add bonus for a two day new release rental
        if ((genre_ == Movie::NEW_RELEASE) && daysRented_ > 1) m_renterPoint++;
    }
}

std::string Customer::printReceipt()
{
    // result will be returned by statement()
    std::ostringstream result;
    result << "Rental Record for " << getName() << "\n";

    int i = 0;
    float sum = 0;
    for (auto each : m_customerRentals)
    {
        result << "\t" << each.getMovie().getTitle() << "\t"
            << m_totalAmount[i] << std::endl;
        sum += m_totalAmount[i];
        i++;
    }

    // Add footer lines
    result << "Amount owed is " << sum << "\n";
    result << "You earned " << m_renterPoint
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
        auto movie_ = m_customerRentals[i].getMovie();
        auto title_ = movie_.getTitle();
        auto genre_ = movie_.getGenre();
        auto daysRented_ = m_customerRentals[i].getDaysRented();
        auto amount_ = getAmount(genre_, daysRented_);
        
        // Show figures for this rental
        result << "\t" << movie_.getGenreString(genre_) << "\t" << title_ << "\t"
            << daysRented_ << "\t" << amount_ << std::endl;
    }

    return result.str();
}

float Customer::getAmount(int code, int dayRented)
{
    float thisAmount = 0.;

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
