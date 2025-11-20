#ifndef LISTARRAY_H
#define LISTARRAY_h

#include <ostream>
#include "List.h"
#include <stdexcept>

template <typename T>
class ListArray : public List<T>
		  private:
			  T* arr;
			  int max;
			  int n;
			  static const int MINSIZE = 2;
			  void resize (int new_size) {
			  T* arr = new T[n];
			  }
				  
		  
		   public:
		   	  void insert(int pos,T e) override {
				 if (pos < 0 || pso > n){
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
			ListArray(){
				T arr[MINISIZE] = 
			~ListArray(){
				delete arr[];
			}
