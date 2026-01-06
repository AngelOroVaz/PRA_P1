#ifndef LISTARRAY_H
#define LISTARRAY_H

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
			  void insert(int pos, T e) override {
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
			virtual T operator[] (int pos) const override{
				if(pos < 0 || pos >= this->size()){
					throw std::out_of_range("Posicion fuera del rango valido");		                   }
				return this->arr[pos];
			}
			T remove(int pos) override {
				if (pos < 0 || pos >= n) {
					throw std::out_of_range("Posicion fuera de rango en remove()");
				}
				T removed = arr[pos];
				for (int i = pos; i < n - 1; ++i) {
					arr[i] = arr[i + 1];
				}
				--n;
				return removed;
			}
			template <typename U>
			friend std::ostream& operator<<(std::ostream& out, const ListArray<U>& list);
};
template <typename T>
std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
	out << "[";
	for (int i = 0; i < list.size(); i++) {
		out << list[i];
		if (i < list.size() - 1) out << ", ";
	}
	out << "]";
	return out;
}

#endif
