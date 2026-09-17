

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include        <string>
#include        <ostream>

class   BigInt
{
        public:
                BigInt( void );
                BigInt( int );
                BigInt( const std::string& );
                BigInt( const BigInt& );
                BigInt& operator=( const BigInt& );
                ~BigInt( void );
                const std::string       getSequence( void ) const;
                void                    setSequence( std::string );

                BigInt operator+( BigInt& );

                bool    operator>( const BigInt& );
                bool    operator<( const BigInt& );
                bool    operator<=( const BigInt& );
                bool    operator>=( const BigInt& );
                bool    operator==( const BigInt& );
                bool    operator!=( const BigInt& );
        
        private:
                std::string     sequence;
};

void                    handlerSequence( std::string& );
bool                    isValid( const std::string& );
std::ostream&           operator<<( std::ostream&, const BigInt& );

#endif