/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication6;

class circle implements figure,location{
    protected final double r;
    protected final double x,y;
    public circle(double r,double x,double y)
    {
        this.r=r;
        this.x=x;
        this.y=y;
    }
    @Override
    public double P(){
        return 2*r*Math.PI;
    }
    @Override
    public double S(){
        return r*r*Math.PI;
    }
    @Override
    public String toString(){
        return "Радиус: "+r+"Координаты: ("+x+","+y+")";
    }
        public static double RST(double x1,double y1,double x2,double y2)
    {
        return Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    }
    @Override
    public int Location(Object o)
    {
        
        if(!(o instanceof circle))
        {
            rect S=(rect)o;
            if(RST(S.x1+(S.x2-S.x1)/2,S.y1+(S.y2-S.y1)/2,this.x,this.y)<this.r+(S.x2-S.x1)/2||RST(S.x1+(S.x2-S.x1)/2,S.y1+(S.y2-S.y1)/2,this.x,this.y)<this.r+(S.y2-S.y1)/2)
                   return 3;
           double help=0.0001;
           double start=0,finish=0;
           if(this.x<=S.x1&&this.y<=S.y2&&this.x>=S.y1){
           start=S.y1;
           finish=S.y2;
           while(start<=finish)
           {
               if((S.x1-this.x)*(S.x1-this.x)+((start-this.y)*(start-this.y))==this.r*this.r)
               {
                   return 2;
               }
               start+=help;
           }
           }
           if(this.x>=S.x1&&this.y>=S.y2&&this.y<=S.x2){
          start=S.x1;
          finish=S.x2;
           while(start<=finish)
           {
               if((start-this.x)*(start-this.x)+((S.y2-this.y)*(S.y2-this.y))==this.r*this.r)
               {
                   return 2;
               }
               start+=help;
           }}
           if(this.x>=S.x2&&this.y<=S.y2&&this.y>=S.y1){
         start=S.y2;
          finish=S.y1;
           while(start>=finish)
           {
               if((S.x2-this.x)*(S.x2-this.x)+((start-this.y)*(start-this.y))==this.r*this.r)
               {
                   return 2;
               }
               start-=help;
           }}
           if(this.x>=S.x1&&this.y<=S.y1&&this.x<=S.x2){
            start=S.x2;
          finish=S.x1;
           while(start>=finish)
           {
               if((start-this.x)*(start-this.x)+((S.y1-this.y)*(S.y1-this.y))==this.r*this.r)
               {
                   return 2;
               }
               start-=help;
           }}
           
            return 1;               
        }
        else{
        circle S=(circle)o;
        if(RST(this.x,this.y,S.x,S.y)>this.r+S.r)
        return 1;
        if(RST(this.x,this.y,S.x,S.y)==this.r+S.r)
        return 2;
        if(RST(this.x,this.y,S.x,S.y)<=this.r+S.r) 
        return 3;
        return 0;}
             
    }
    }
