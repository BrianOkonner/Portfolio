#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream.h>
using namespace std;

// предшествующий принятию стандарта синтаксис <iostream>

class GreaterThan {
public:
   GreaterThan( int sz = 6 ) : _size( sz ){}
   int size() { return _size; }

   bool operator()(const string &s1)
                  { return s1.size() >_size; }
private:
   int _size;
};

class PrintElem {
public:

   PrintElem( int lineLen = 8 )
      : _line_length( lineLen ), _cnt( 0 )
   {}

   void operator()( const string &elem )
   {
      ++_cnt;
      if ( _cnt % _line_length == 0 )
         { cout << '\n'; }
	cout<<elem.c_str()<<" ";
   }

private:
   int _line_length;
   int _cnt;
};
class LessThan {
public:
   bool operator()( const string & s1,
                   const string & s2 )
   { return s1.size() < s2.size();	}
};

typedef vector<string> textwords;

void process_vocab( vector<textwords> *pvec )
{
   if ( ! pvec ) {
	 // вывести предупредительное сообщение
     return;
   }

   vector< string > texts;

   vector<textwords>::iterator iter;
   for ( iter = pvec->begin() ; iter != pvec->end(); ++iter )
      copy( (*iter).begin(), (*iter).end(),
              back_inserter( texts ));

   // отсортировать вектор texts
   sort( texts.begin(), texts.end() );

   // теперь посмотрим, что получилось
   for_each( texts.begin(), texts.end(), PrintElem() );

   cout << "\n\n";   // разделить части выведенного текста

   // удалить дубликаты
   vector<string>::iterator it;
   it = unique( texts.begin(), texts.end() );
   texts.erase( it, texts.end() );

   // посмотрим, что осталось
   for_each( texts.begin(), texts.end(), PrintElem() );
   cout << "\n\n";

   // отсортировать элементы
   // stable_sort сохраняет относительный порядок равных элементов
   stable_sort( texts.begin(), texts.end(), LessThan() );
   for_each( texts.begin(), texts.end(), PrintElem() );

   cout << "\n\n";

   // подсчитать число строк, длина которых больше 6
   int cnt = 0;

   // устаревшая форма count - в стандарте используется другая
   cnt = count_if( texts.begin(), texts.end(), GreaterThan());

   cout <<"Number of words greater than length six are "
       << cnt  << endl;

   static string rw[] = { "and", "if", "or", "but", "the" };
   vector <string > remove_words( rw, rw+5 );

   vector <string >::iterator it2 = remove_words.begin();

   for ( ; it2 != remove_words.end(); ++it2 )
   {
      int cnt = 0;

      // устаревшая форма count - в стандарте используется другая
      cnt = count( texts.begin(), texts.end(), *it2 );
	
      cout << cnt    << " instances removed:  "
           << (*it2).c_str()<< endl;

      texts.erase(
         remove(texts.begin(),texts.end(),*it2),
                texts.end()
      );
   }
   cout << "\n\n";
   for_each( texts.begin(), texts.end(), PrintElem() );
}


using namespace std;
main()
{
     vector<textwords> sample;
     vector<string>  t1, t2;
     char  t1fn[20], t2fn[20];

	// запросить у пользователя имена входных файлов ...
	// в реальной программе надо бы выполнить проверку
     cout << "text file #1: "; 
	 cin >>  t1fn;
     cout << "text file #2: "; 
	 cin >>  t2fn;

	// открыть файлы
     ifstream infile1( t1fn);
     ifstream infile2( t2fn);

	// специальная форма итератора
	// обычно diff_type подразумевается по умолчанию ...
     istream_iterator<  string >  input_set1( infile1 ), eos;
     istream_iterator<  string >  input_set2( infile2 );

	// специальная форма итератора
     copy( input_set1, eos, back_inserter( t1 ));
     copy( input_set2, eos, back_inserter( t2 ));

     sample.push_back( t1 ); sample.push_back( t2 );
     process_vocab( &sample );
}

