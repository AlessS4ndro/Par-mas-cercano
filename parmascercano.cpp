/*
                            DADO UN CONJUNTO DE PUNTOS DETERMINAR EL PAR MAS CERCANO

----------------------------  PLAN PARA RESOLVER EL PAR MAS CERCANO -----------------

  1.- ORDENAREMOS TODOS LOS PUNTOS DE ACUERDO AL EJE X
  2.- TRAZAREMOS UNA RECTA VERTICAL Q CORTE AL EJE X POR LA MITAD SEGUN LOS PUNTOS
    2.2.- CREAMOS DOS ARREGLOS CON LA MITAD DE ELEMENTOS DEL ARREGLO QUE LLAMA ALA FUNCION
    2.3.- REALIZAREMOS LA RECURSIVIDAD EN EL PASO 2.2 HASTA QUE EL ARREGLO TENGA UN TAMAÑO <= 3
    2.4.- RETORNAREMOS LA DISTANCIA MINIMA
  3.-

  1.CREAREMOS LA FUNCION distancia;
  2.CREAREMOS LA FUNCION

*/
#include<iostream>
#include<math.h>

using namespace std;

struct Punto
{
  friend istream & operator>>(istream &i,const Punto &p);
  friend ostream & operator<<(ostream &,const Punto &);
  Punto(){}
  Punto(float x,float y){this->x=x;this->y=y;}
  float x;
  float y;
};

ostream & operator<<(ostream &o,Punto &p)
{
  o<<"("<<p.x<<","<<p.y<<")";
  return o;
}

istream & operator>>(istream &i,Punto &p)
{
  i>>p.x>>p.y;
  return i;
}

float distancia(Punto p1,Punto p2)
{
  float n1=pow((p1.x-p2.x),2);
  float n2=pow((p1.y-p2.y),2);
  return sqrt(n1+n2);
}

float caso_particular(Punto ps[],int len ,float dmin)
{
  int n=ceil(dmin);
  cout<<"ceil es..... "<<n<<endl;
  int medio=len/2;
  cout<<"el mendio es... "<<medio<<endl;

  cout<<"form.."<<(2*n)-1<<endl;
  for(int i=0;i<((2*n)-1);i++){
    cout<<"interando.....";
    for(int j=i+1;j<(2*n)-1;j++){
      float d=distancia(ps[medio-n+i],ps[medio-n+j]);   ///   hallamos la distancia del primer punto
      cout<<"distancia hallada entre "<<ps[medio-n+i]<<" y"<<ps[medio-n+j]<<"ees..."<<d<<endl;
      if( d < dmin){
        cout<<"reemplazando distancia minima"<<endl;                                      //   con el punto siguiente
        dmin=d;
      }
    }
  }
}



float partir_arreglo(Punto nuevo[],int len1,Punto  remoto[],int i)
{
  for(int j=0;j<len1;j++){
    nuevo[j]=remoto[i++];
  }
}

void par_mas_cercano(Punto as[],int len,float &dmin)
{
  cout<<"INICIANDO LA FUNCION PARMASCERCANO"<<endl;
  float auxiliarlen=len;
  cout<<"\t\t!!distancia minima = "<<dmin<<endl;
  cout<<" \t\t!!len del arreglo = "<<len<<endl;

  cout<<"evaluamos tamaño == 2\n";
  if(len==2){
    cout<<"\t\t!!LEN == 2\n";
    float dactual=distancia(as[0],as[1]);
    cout<<"ejecutamos funcion distancia ...: "<<dactual<<" de los puntos as[0],as[1] respectivamente..: "<<as[0]<<","<<as[1]<<endl;
    if(dactual<dmin){
      dmin=dactual;
    }
    cout<<"\t\t!!distancia minima = "<<dmin<<endl;
    return;
  }
  cout<<"evaluamos tamaño ==3\n";
  if(len==3){
    cout<<"\t\t !!!LEN == 3\n";
    float d1=distancia(as[0],as[1]);
    cout<<"ejecutamos funcion distancia ...: "<<d1<<" de los puntos as[0],as[1] respectivamente..: "<<as[0]<<","<<as[1]<<endl;
    float d2=distancia(as[0],as[2]);
    cout<<"ejecutamos funcion distancia ...: "<<d2<<" de los puntos as[0],as[2] respectivamente..: "<<as[0]<<","<<as[2]<<endl;
    float d3=distancia(as[1],as[2]);
    cout<<"ejecutamos funcion distancia ...: "<<d3<<" de los puntos as[1],as[2] respectivamente..: "<<as[1]<<","<<as[2]<<endl;
    if(d1<=d2 && d1<=d3 && d1<dmin) dmin=d1;
    if(d2<=d1 && d2<=d3 && d2<dmin) dmin=d2;
    if(d3<=d1 && d3<=d2 && d3<dmin) dmin=d3;
    cout<<"\t\t!!distancia minima = "<<dmin<<endl;
    return ;
  }
  cout<<"el ceil es............"<<ceil(auxiliarlen/2)<<endl;
  int lenizquierdo=int(ceil(auxiliarlen/2));
  Punto izquierdo[lenizquierdo];             /////////   creamos un arreglo izquierdo
  cout<<"creo arreglo hijo izquierod\n";
  cout<<"el lenizquierdo es....... "<<lenizquierdo<<endl;
  partir_arreglo(izquierdo,lenizquierdo,as,0);
  Punto derecho[len/2];                         /////////   creamos un arreglo derecho
  cout<<"creo arreglo hijo derecho\n";
  cout<<"el lenderecho es....... "<<len/2<<endl;
  partir_arreglo(derecho,len/2,as,len-(len/2));

  cout<<"recursividad en izquierdo\n";
  par_mas_cercano(izquierdo,lenizquierdo,dmin);
  cout<<"recursividad en derecho\n";
  par_mas_cercano(derecho,len/2,dmin);

}

int main ()
{
  Punto ps[11];
  ps[0].x=0;ps[0].y=10;
  ps[1].x=1.5;ps[1].y=10;
  ps[2].x=2;ps[2].y=11;
  ps[3].x=3;ps[3].y=10;
  ps[4].x=4;ps[4].y=15;
  ps[5].x=5;ps[5].y=10;
  ps[6].x=6;ps[6].y=13;
  ps[7].x=7;ps[7].y=10;
  ps[8].x=8;ps[8].y=-5;
  ps[9].x=9;ps[9].y=-3;
  ps[10].x=9;ps[10].y=10;

  float dist=distancia(ps[0],ps[10]);
  cout<<"distancia inicial es ....... "<<dist<<endl;

  //par_mas_cercano(ps,11,dist);
  //cout<<"la distancia minima final es..........."<<dist<<endl;
  caso_particular(ps,11,2.4);

  return 0;
}
