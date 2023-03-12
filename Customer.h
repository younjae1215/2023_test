// Customer.hh
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Rental.h"

// The customer class represents the customer of the store

class Customer {
public:
  Customer();
  explicit Customer( const std::string& name );

  void addRental( const Rental& arg );
  void addRental(const Movie& rental, const int daysRented);

  std::string getName() const;

  // Generate a statement for the customer
  //std::string statement();
  std::string statement_();

  // 새로운 출력형식 추가
  std::string newStatement();

  std::string printReceipt();
  void updateCustomerData();

  float getAmount(int priceCode, int daysRented);

private:
  std::string m_customerName;
  std::vector< Rental > m_customerRentals;
  std::vector<float> m_totalAmount;
  int m_renterPoint = 0;
};


inline Customer::Customer() {}

inline Customer::Customer( const std::string& name ): 
  m_customerName( name ) {}

inline void Customer::addRental( const Rental& arg ) { m_customerRentals.emplace_back( arg ); }

// 명시적으로 다른 사용자들이 헷갈리지 않게 보여주는 것도 괜찮아보임
inline void Customer::addRental(const Movie& movie, const int daysRented)
{
	m_customerRentals.emplace_back(Rental(movie, daysRented));
}

inline std::string Customer::getName() const { return m_customerName; }

#endif // CUSTOMER_HH
