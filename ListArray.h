#ifndef LISTARRAY_H
#define LISTARRAY_h

#include <ostream>
#include "List.h"
#include <stdexcept>

template <typename T>
class ListArray : public List<T>{
		  private:
			  T* arr;
			  int max;
			  int n;
			  static const int MINSIZE = 2;
			  
			  void resize (int new_size) {
			  	T* new_arr = new T[new_size];
			  	for (int i = 0; i < n; ++i){
				  new_arr[i] = arr[i];
			  	}
			  	delete[] arr;
			  	arr = new_arr;
			  	max = new_size;
			   }
				  
		  
		   public:
			ListArray(){
				arr = new T[MINSIZE];
				max = MINSIZE;
				n = 0;
			}

			~ListArray(){
				delete[] arr;
			}

			
			  int size() const override {
				  return n;
			  }
			  void insert(int pos,T e) override {
				 if (pos < 0 || pos > n){
					throw std::out_of_range("Posicion invalida en insert()");
				 }
				 if (n == max){
					 resize(max * 2);
				}
				 for (int i = n; i > pos; i--)
					 arr[i] = arr[i - 1];

				 arr[pos] = e;
				 n++;
			}
			void append(T e) override {
				insert(n,e);
			}
			void prepend(T e) override {
				insert(0, e);
			}
			T operator[] (int pos) override{
				if(pos < 0 || pos >= n){
					throw std::out_of_range("Posicion fuera del rango valido");		                   }
				return arr[pos];
			}
			template <typename U>
			friend std::ostream&operator<<(std::ostream&out, const ListArray<U>&list);
};
template <typename T>
std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
	out << "[";
	for (int i = 0; i < list.size(); i++) {
		out << list.arr[i];
		if (i < list.size() - 1) out << ", ";
	}
	out << "]";
	return out;
}

#endif
