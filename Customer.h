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
  std::string getName() const;

  // Generate a statement for the customer
  std::string statement();

  // 새로운 출력형식 추가


private:
  std::string m_customerName;
  std::vector< Rental > m_customerRentals;

};


inline Customer::Customer() {}

inline Customer::Customer( const std::string& name ): 
  m_customerName( name ) {}

// arg로 입력을 받는데, 영화제목과 대여 기간으로 입력이 고정된 상황인것 같음
// 명시적으로 다른 사용자들이 헷갈리지 않게 보여주는 것도 괜찮아보임
// 복사를 거치니 emplace_back()이 나아보임
inline void Customer::addRental( const Rental& arg ) { m_customerRentals.push_back( arg ); }

inline std::string Customer::getName() const { return m_customerName; }

#endif // CUSTOMER_HH
