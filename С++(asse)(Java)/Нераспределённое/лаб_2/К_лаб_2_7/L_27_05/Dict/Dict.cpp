#include <map>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main()
{
   map< string, string > trans_map;
   typedef map< string, string >::value_type valType;

   // первое упрощение:
   // жестко заданный словарь
   trans_map.insert( valType( "gratz", "grateful" ));
   trans_map.insert( valType( "'em", "them" ));
   trans_map.insert( valType( "cuz", "because" ));
   trans_map.insert( valType( "nah", "no" ));
   trans_map.insert( valType( "sez", "says" ));
   trans_map.insert( valType( "tanx", "thanks" ));
   trans_map.insert( valType( "wuz", "was" ));
   trans_map.insert( valType( "pos", "suppose" ));

   // напечатаем словарь
   map< string,string >::iterator it;

   cout << "Our Dictionary: \n\n";
   for ( it = trans_map.begin();
         it != trans_map.end(); ++it )
     cout << "The key: " << (*it).first << "\t"
           <<"A value: " << (*it).second << "\n";
   cout << "\n\n";

   // второе упрощение: жестко заданный текст
  string textarray[14]={ "nah", "I", "sez", "tanx",
         "cuz", "I", "wuz", "pos", "to", "not",
         "cuz", "I", "wuz", "gratz" };
   vector< string > text( textarray, textarray+14 );
   vector< string >::iterator iter;

   // напечатаем текст
   cout << "The old string vector:\n\n";
   int cnt = 1;
   for ( iter = text.begin(); iter != text.end();
               ++iter,++cnt )
      cout << *iter << ( cnt % 8 ? " " : "\n" );

   cout << "\n\n\n";

   // map для сбора статистики
   map< string,int > stats;
   typedef map< string,int >::value_type statsValType;
   // здесь происходит реальная работа
   for ( iter=text.begin(); iter != text.end(); ++iter )
   if (( it = trans_map.find( *iter ))
            != trans_map.end() )
   {
      if ( stats.count( *iter ))
         stats [ *iter ] += 1;
      else stats.insert( statsValType( *iter, 1 ));
      *iter = (*it).second;
   }

   // напечатаем преобразованный текст
   cout << "A new string vector:\n\n";
   cnt = 1;
   for ( iter = text.begin(); iter != text.end();
      ++iter, ++cnt )
   cout << *iter << ( cnt % 8 ? " " : "\n" );
        cout << "\n\n\n";

   // напечатаем статистику
   cout << "A statistics:\n\n";
   map<string,int>::iterator siter;

   for (siter=stats.begin(); siter!=stats.end(); ++siter)
      cout << (*siter).first << " "
           << "has replaced "
           << (*siter).second
           << (" times\n" );
}
