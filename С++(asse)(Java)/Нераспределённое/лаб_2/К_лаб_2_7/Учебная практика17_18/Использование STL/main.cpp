#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
 using namespace std;
//int main()
//{
//    const size_t row = 5;
//    const size_t col = 3;
//    std::vector<std::vector<int>> imatrix (row);
//    // Заполнение
//    for(size_t i = 0; i < row; ++i)
//    {
//      //  imatrix[i].resize(col);
//        for(size_t j = 0; j < col; ++j)
//            imatrix[i][j] = rand() % 123;
//    }
//
//	 for(size_t i = 0; i < row; ++i)
//    {
//        //imatrix[i].resize(col);
//        for(size_t j = 0; j < col; ++j)
//		
//          //  imatrix[i][j] = rand() % 123;
//		  cout<<imatrix[i][j]<<"  ";
//		cout<<endl;
//    }
//   
//    system("pause");
//    return 0;
//}


 #include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
  using namespace std;
int main()
{
    const size_t row = 5;
    const size_t col = 3;
    std::vector<std::vector<int> > imatrix;
    // Заполнение
    for(size_t i = 0; i < row; ++i)
    {
        std::vector<int> temp;
        for(size_t j = 0; j < col; ++j)
            temp.push_back(rand() % 100);
        imatrix.push_back(temp);
    }
   //  Печать

		 for(size_t i = 0; i < row; ++i)
    {
        //imatrix[i].resize(col);
        for(size_t j = 0; j < col; ++j)
		
          //  imatrix[i][j] = rand() % 123;
		  cout<<imatrix[i][j]<<"  ";
		cout<<endl;
		 }
    system("pause");
    return 0;
}



