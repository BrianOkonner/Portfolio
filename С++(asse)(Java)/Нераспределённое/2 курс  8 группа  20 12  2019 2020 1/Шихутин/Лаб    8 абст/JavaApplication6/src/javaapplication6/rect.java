/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication6;
class rect implements figure,location{
    protected double x1,x2,y1,y2;
    public rect(double x1,double y1,double x2,double y2)
    {
        this.x1=x1;
        this.x2=x2;
        this.y1=y1;
        this.y2=y2;
    }
        public static double RST(double x1,double y1,double x2,double y2)
    {
        return Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    }
     @Override
    public double P(){
        return 2*(Math.abs(x1-x2)+Math.abs(y1-y2));
    }
    @Override
    public double S(){
        return Math.abs(x1-x2)*Math.abs(y1-y2);
    }
    @Override
    public String toString(){
        return "Координаты: ("+x1+","+y1+"),("+x2+","+y2+")";
    }
    @Override
    public int Location(Object o)
    {
        if((o instanceof rect))
        {
            rect S=(rect)o;
            if(S.x1<this.x2&&S.x1>this.x1&&S.y1<this.y2&&S.y1>this.y1||
               S.x1<this.x2&&S.x1>this.x1&&S.y2<this.y2&&S.y2>this.y1||
                    S.x2<this.x2&&S.x2>this.x1&&S.y1<this.y2&&S.y1>this.y1||
                    S.x2<this.x2&&S.x2>this.x1&&S.y2<this.y2&&S.y2>this.y1)  
                return 3;
            if(S.x1<=this.x2&&S.x1>=this.x1&&S.y1<=this.y2&&S.y1>=this.y1||
               S.x1<=this.x2&&S.x1>=this.x1&&S.y2<=this.y2&&S.y2>=this.y1||
                    S.x2<=this.x2&&S.x2>=this.x1&&S.y1<=this.y2&&S.y1>=this.y1||
                    S.x2<=this.x2&&S.x2>=this.x1&&S.y2<=this.y2&&S.y2>=this.y1) 
                return 2;
            return 1;
        }
        else
        {
           circle S=(circle)o;
            if(RST(this.x1+(this.x2-this.x1)/2,this.y1+(this.y2-this.y1)/2,S.x,S.y)<S.r+(this.x2-this.x1)/2||RST(this.x1+(this.x2-this.x1)/2,this.y1+(this.y2-this.y1)/2,S.x,S.y)<S.r+(this.y2-this.y1)/2)
                   return 3;
           double help=0.0001;
           double start=0,finish=0;
           if(S.x<=this.x1&&S.y<=this.y2&&S.x>=this.y1){
           start=this.y1;
           finish=this.y2;
           while(start<=finish)
           {
               if((this.x1-S.x)*(this.x1-S.x)+((start-S.y)*(start-S.y))==S.r*S.r)
               {
                   return 2;
               }
               start+=help;
           }
           }
           if(S.x>=this.x1&&S.y>=this.y2&&S.y<=this.x2){
          start=this.x1;
          finish=this.x2;
           while(start<=finish)
           {
               if((start-S.x)*(start-S.x)+((this.y2-S.y)*(this.y2-S.y))==S.r*S.r)
               {
                   return 2;
               }
               start+=help;
           }}
           if(S.x>=this.x2&&S.y<=this.y2&&S.y>=this.y1){
         start=this.y2;
          finish=this.y1;
           while(start>=finish)
           {
               if((this.x2-S.x)*(this.x2-S.x)+((start-S.y)*(start-S.y))==S.r*S.r)
               {
                   return 2;
               }
               start-=help;
           }}
           if(S.x>=this.x1&&S.y<=this.y1&&S.x<=this.x2){
            start=this.x2;
          finish=this.x1;
           while(start>=finish)
           {
               if((start-S.x)*(start-S.x)+((this.y1-S.y)*(this.y1-S.y))==S.r*S.r)
               {
                   return 2;
               }
               start-=help;
           }}
           
            return 1;  
        }
        
    }
}