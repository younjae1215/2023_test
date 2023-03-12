// Movie.hh
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <vector>

class Movie {
public:
  // 얘네만 따로 enum해도 괜찮을듯
  //static const int CHILDRENS   = 2;
  //static const int REGULAR     = 0;
  //static const int NEW_RELEASE = 1;
  //static const int EXAMPLE_GENRE = 3;

  enum Genre {
	  REGULAR = 0,
	  NEW_RELEASE,
	  CHILDRENS,
	  EXAMPLE_GENRE,
  };

  // 장르 기본 일반
  Movie( const std::string& title, int priceCode = REGULAR );

  int getPriceCode() const;
  void setPriceCode( int arg );
  std::string getTitle() const;
  std::string getGenreString(int genre) const;

private:
  std::string m_movieTitle;
  int m_moviePriceCode;
  const std::vector<std::string> m_genre_str{ "REGULAR", "NEW_RELEASE", "CHILDREN", "EXAMPLE_GENRE" };

};

inline Movie::Movie( const std::string& title, int priceCode ): 
	m_movieTitle( title ),
	m_moviePriceCode( priceCode )
{}

inline int Movie::getPriceCode() const { return m_moviePriceCode; }

inline void Movie::setPriceCode( int arg ) { m_moviePriceCode = arg; }

inline std::string Movie::getTitle() const { return m_movieTitle; }

inline std::string Movie::getGenreString(int genre) const { return m_genre_str[genre]; }
#endif // MOVIE_H
