#include        <stack>
#include        <cctype>
#include        <string>
#include        <sstream>
#include        <iostream>

#include        "../header/BigInt.hpp"

static bool    isValid( std::string& );
static void    handlerSequence( std::string& );
static std::size_t      convert( const std::string& );


BigInt::BigInt( void )
        : sequence( std::string("0") )
{ /* empty body */ }

BigInt::BigInt( int _intValue )
{
        std::stringstream       _sstr;
        _sstr << _intValue;

        this->sequence = _sstr.str();
}

BigInt::BigInt( const std::string& _sqc )
{
        this->setSequence( _sqc );
}

BigInt::BigInt( const BigInt& _big )
        : sequence( _big.sequence )
{ /* empty body */ }

BigInt& BigInt::operator=( const BigInt& _big )
{
        if ( this != &_big )
        {
                this->sequence = _big.getSequence();
        }
        return *this;
}

BigInt::~BigInt( void )
{ /* empty body */ }

const std::string   BigInt::getSequence( void ) const
{
        return this->sequence;
}

std::ostream&    operator<<( std::ostream& _out, const BigInt& _big )
{
        _out << _big.getSequence();
        return _out;
}

BigInt BigInt::operator+( const BigInt& _bigint ) const
{
        int     rst = 0;
        std::stack<char>        _stack;

        std::string     _s1 = this->sequence;
        std::string     _s2 = _bigint.sequence;

        if ( *this < _bigint )
        {
                _s2 = this->sequence;
                _s1 = _bigint.sequence;
        }

        std::string::iterator   _end_s1 = _s1.end();
        std::string::iterator   _end_s2 = _s2.end();

        while ( _end_s1 != _s1.begin() )
        {
                --_end_s1;
                if ( _end_s2 != _s2.begin() )
                        --_end_s2;
                else
                        *_end_s2 = '0';
                rst += *_end_s1 - '0' + *_end_s2 - '0';
                std::stringstream       _sts;
                _sts << rst;
                if ( _sts.str().size() > 1 )
                {
                        rst = _sts.str()[0] - '0';
                        _stack.push( _sts.str()[1]);
                }
                else
                {
                        _stack.push( _sts.str()[0] );
                        rst = 0;
                }
        }
        if ( rst > 0 )
                _stack.push( rst + '0' );

        char    _c_st[ _stack.size() ];
        
        int     _stack_sz = static_cast<int>(_stack.size());
        int     _i = 0;

        _c_st[_stack_sz] = 0;
        while ( _i < _stack_sz )
        {
                _c_st[ _i ] = _stack.top();
                _stack.pop();
                _i++;
        }

        BigInt  _bigR;
        _bigR.sequence = _c_st;
        return _bigR;
}

void    BigInt::setSequence( std::string _sqc )
{
        !isValid( _sqc )
                ? this->sequence = "0"
                : this->sequence = _sqc;
        handlerSequence( this->sequence );
}

bool    BigInt::operator>( const BigInt& _bigint ) const
{
        std::string     _s1 = this->sequence;
        std::string     _s2 = _bigint.sequence;
        std::string     _s3;

        if ( _s1.size() > _s2.size() )
                return true;
        else if ( _s1.size() < _s2.size() )
                return false;
        else
        {
                int     i = 0;
                int     size = _s1.size();

                while ( i < size && _s1[i] == _s2[i] )
                        i++;
                if ( i != size )
                {
                        if ( _s1[i] > _s2[i] )
                                return true;
                        return  false;
                }
                return false;
        }
}

bool    BigInt::operator<( const BigInt& _bigint ) const
{
        std::string     _s1 = _bigint.sequence;
        std::string     _s2 = this->sequence;
        std::string     _s3;

        if ( _s1.size() > _s2.size() )
                return true;
        else if ( _s1.size() < _s2.size() )
                return false;
        else
        {
                int     i = 0;
                int     size = _s1.size();

                while ( i < size && _s1[i] == _s2[i] )
                        i++;
                if ( i != size )
                {
                        if ( _s1[i] > _s2[i] )
                                return true;
                        return  false;
                }
                return false;
        }
}

bool    BigInt::operator<=( const BigInt& _bigint ) const
{
        std::string     _s1 = _bigint.sequence;
        std::string     _s2 = this->sequence;
        std::string     _s3;

        if ( this->operator<(_bigint) )
                return true;
        else if ( this->operator>(_bigint) )
                return false;
        else
        {
                int     i = 0;
                int     size = _s1.size();

                while ( i < size && _s1[i] == _s2[i] )
                        i++;
                if ( i != size )
                {
                        if ( _s1[i] < _s2[i] )
                                return true;
                        return  false;
                }
                return true;
        }
}

bool    BigInt::operator>=( const BigInt& _bigint ) const
{
        std::string     _s1 = this->sequence;
        std::string     _s2 = _bigint.sequence;
        std::string     _s3;

        if ( this->operator>(_bigint) )
                return true;
        else if ( this->operator<(_bigint) )
                return false;
        else
        {
                int     i = 0;
                int     size = _s1.size();

                while ( i < size && _s1[i] == _s2[i] )
                        i++;
                if ( i != size )
                {
                        if ( _s1[i] > _s2[i] )
                                return true;
                        return  false;
                }
                return true;
        }
}

bool    BigInt::operator==( const BigInt& _bigint ) const
{
        std::string     _s1 = this->sequence;
        std::string     _s2 = _bigint.sequence;

        if ( this->sequence.size() != _bigint.sequence.size() )
                return false;
        else
        {
                int     i = 0;
                int     size = _s1.size();

                while ( i < size && _s1[i] == _s2[i] )
                        i++;
                if ( i != size )
                        return false;
                return true;
        }
}
bool    BigInt::operator!=( const BigInt& _bigint ) const
{
        std::string     _s1 = this->sequence;
        std::string     _s2 = _bigint.sequence;

        if ( this->sequence.size() != _bigint.sequence.size() )
                return true;
        else
        {
                int     i = 0;
                int     size = _s1.size();

                while ( i < size && _s1[i] == _s2[i] )
                        i++;
                if ( i != size )
                        return true;
                return false;
        }
}

BigInt& BigInt::operator+=( const BigInt& _bigint )
{
        this->sequence = this->operator+(_bigint).sequence;
        return *this;
}

BigInt& BigInt::operator++( void )
{
        BigInt  _one( 1 );
        *this = this->operator+(  _one );
        return *this;
}

BigInt BigInt::operator++( int )
{
        BigInt  _result = *this;
        ++(*this);
        return _result;
}

BigInt  BigInt::operator<<( const BigInt& _bigint ) const
{
        std::string     _sequence = this->sequence;
        std::size_t n = convert( _bigint.sequence );
        std::size_t i = 0;

        while ( i < n )
        {
                _sequence = _sequence + "0";
                i++;
        }
        BigInt  _bigintR( _sequence );
        return _bigintR;
}

BigInt&  BigInt::operator<<=( const BigInt& _bigint )
{
        std::string     _sequence = this->sequence;
        std::size_t n = convert( _bigint.sequence );
        std::size_t i = 0;

        while ( i < n )
        {
                _sequence = _sequence + "0";
                i++;
        }
        this->sequence = _sequence;
        return *this;
}

/* --------------------- static function -------------------- */

static void    handlerSequence( std::string& _sqc )
{
        if ( _sqc.size() == 1 && std::isdigit(_sqc[ 0 ]) )
                return ;
        std::size_t      _index = _sqc.find( '+', 0 );
        _index == std::string::npos ? _index = 0 : _index++;
        _sqc = _sqc.substr( _index, _sqc.size());
}

static bool    isValid( std::string& _sqc )
{
        std::size_t     i = 0;
        if ( _sqc[i] == 43 )
                ++i;
        while ( std::isdigit( _sqc[i] ) )
                ++i;
        if ( _sqc[i] != 0 && !std::isdigit(_sqc[i]) )
                return false;
        return true;
}

static std::size_t      convert( const std::string& _str )
{
        std::size_t     rst = 0;
        std::size_t     _size = _str.size();
        std::size_t     _index = 0;

        while ( _index < _size )
        {
                rst = rst * 10 + ( _str[_index] - '0' );
                ++_index;
        }

        return rst;
}

// std::string     compare( const std::string& _s1, const std::string& _s2 )
// {
//         std::string     _s3;

//         if ( _s1.size() > _s2.size() )
//                 return _s1;
//         else if ( _s1.size() < _s2.size() )
//                 return _s2;
//         else
//         {
//                 int     i = 0;
//                 int     size = _s1.size();

//                 while ( i < size && _s1[i] == _s2[i] )
//                         i++;
//                 if ( i != size )
//                 {
//                         _s1[i] > _s2[i] ? _s3 = _s1 : _s3 = _s2;
//                         return _s3;
//                 }
//                 return _s1;
//         }
// }
