#include <iostream>

using namespace std;

class ModInt{
  private:
    int num;
    int mod;

  public:
    //constructors
    ModInt(){
      num = 0;
      mod = 0;
    }
    ModInt(int num_, int mod_){
      num = num_;
      mod = mod_;

    }
    //getters
     int getNum(){
       return num;
     }
     int getMod(){
       return mod;
     }

     //non-member functions
     void operator +=(ModInt rhs);



};
//check if lhs and rhs are equal returns 1 if true and 0 if false
bool operator ==(ModInt lhs, ModInt rhs){
  return ((lhs.getNum() == rhs.getNum()) && (lhs.getMod() == rhs.getMod()));
}

void ModInt::operator +=(ModInt rhs){

  if(mod != rhs.mod){
    num = -1;
    mod = -1;
    return;
  }else{
    num += rhs.num;
    num %= rhs.mod;

    }
}

ModInt operator +(ModInt lhs, ModInt rhs){
  int sum = 0;
  if(lhs.getMod() != rhs.getMod()){
    ModInt output(-1,-1);
    return output;
  }else{
    sum = lhs.getNum()+ rhs.getNum();
    ModInt output(sum%lhs.getMod(),lhs.getMod());
    return output;
  }


}



int main(){

  ModInt m1(201,5);
  ModInt m2(200,5);
  cout<<m1.getNum()<<"\t"<<m2.getNum()<<endl;

  if(m1==m2){
  cout<< (m1 == m2)<<endl;
  }
  m1 += m2;
  cout<< " +="<<endl;
  cout<< m1.getNum()<<endl;
  cout<< m1.getMod()<<endl;
  ModInt m3(1323,7);
  ModInt m4(2131,7);
  ModInt m5 = (m3+m4);
  cout<< "+ "<<endl;
  cout<< m5.getNum()<<endl;
  cout<< m5.getMod()<<endl;

  return 0;
}
