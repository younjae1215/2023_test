// Customer.cc
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

std::string Customer::statement()
{
    updateCustomerData();
    auto result = printReceipt();
    result += printReceipt_();
    return result;
}

void Customer::updateCustomerData()
{
    // Loop over customer's rentals
    for (auto& each : m_customerRentals)
    {
        auto genre_ = each.getMovie().getGenre();
        auto daysRented_ = each.getDaysRented();
        auto thisAmount = each.getAmount(genre_, daysRented_);
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
    for (const auto& each : m_customerRentals)
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

std::string Customer::printReceipt_()
{
    std::ostringstream result;
    result << "\n";

    // 장르 제목 대여기간 가격
    const int size = m_customerRentals.size();

    for (int i = 0; i < size; ++i)
    {
        auto movie_ = m_customerRentals[i].getMovie();
        auto title_ = movie_.getTitle();
        auto genre_ = movie_.getGenre();
        auto daysRented_ = m_customerRentals[i].getDaysRented();
        auto amount_ = m_totalAmount[i];
        
        // Show figures for this rental
        result << "\t" << movie_.getGenreString(genre_) << "\t" << title_ << "\t"
            << daysRented_ << "\t" << amount_ << std::endl;
    }

    return result.str();
}

