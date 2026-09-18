

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include        <string>
#include        <ostream>

class   BigInt
{
        public:
                BigInt( int );
                BigInt( void );
                BigInt( const std::string& );
                BigInt( const BigInt& );
                BigInt& operator=( const BigInt& );
                ~BigInt( void );
                const std::string       getSequence( void ) const;
                void                    setSequence( std::string );

                BigInt operator+ ( const BigInt& ) const;
                BigInt& operator+=( const BigInt& );

                BigInt& operator++( void );
                BigInt  operator++( int );

                BigInt  operator<<( const BigInt& ) const;
                BigInt  operator>>( const BigInt& ) const;
                
                BigInt&  operator<<=( const BigInt& );
                BigInt&  operator>>=( const BigInt& );

                bool    operator> ( const BigInt& ) const;
                bool    operator< ( const BigInt& ) const;
                bool    operator<=( const BigInt& ) const;
                bool    operator>=( const BigInt& ) const;
                bool    operator==( const BigInt& ) const;
                bool    operator!=( const BigInt& ) const;
        
        private:
                std::string     sequence;
};

std::ostream&           operator<<( std::ostream&, const BigInt& );

#endif