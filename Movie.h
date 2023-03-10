// Movie.hh
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <vector>

class Movie {
public:
  enum Genre {
	  REGULAR = 0,
	  NEW_RELEASE,
	  CHILDRENS,
	  EXAMPLE_GENRE,
  };

  // 장르 기본 일반
  Movie( const std::string& title, int priceCode = REGULAR );

  int getGenre() const;
  void setGenre( int arg );
  std::string getTitle() const;
  std::string getGenreString(int genre) const;

private:
  std::string m_movieTitle;
  int m_movieGenre;
  const std::vector<std::string> m_genre_str{ "REGULAR", "NEW_RELEASE", "CHILDREN", "EXAMPLE_GENRE" };

};

inline Movie::Movie( const std::string& title, int Genre):
	m_movieTitle( title ),
	m_movieGenre(Genre)
{}

inline int Movie::getGenre() const { return m_movieGenre; }

inline void Movie::setGenre( int arg ) { m_movieGenre = arg; }

inline std::string Movie::getTitle() const { return m_movieTitle; }

inline std::string Movie::getGenreString(int genre) const { return m_genre_str[genre]; }
#endif // MOVIE_H
