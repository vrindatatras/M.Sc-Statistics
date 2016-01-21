#Algorithm for White and Black Balls
rm(list=ls())
LGC <- function(a, c, M, n, y){
  x <- rep(0, n)
  x[1] <- y
  for(i in 1:n)
    x[i+1] <- (a*x[i]+c) %% (M)
  return(x/M)
}
uni_01 <- LGC(23, 0, 10^8, 1000, 123)

x<- rep(0, 1000)
y<- rep(0, 1000)

for(i in 1:1000){
  if(uni_01[i] < 1/3){
    x[i] <- "Urn 1"
    z <- sample(uni_01, 1)
    if(z < 4/7)
      y[i] <- "White"
    else y[i] <- "Black"
  }
  else if(uni_01[i] > 2/3){
    x[i] <- "Urn 3"
    z <- sample(uni_01, 1)
    if(z < 5/6)
      y[i] <- "White"
    else y[i] <- "Black"
  }
  else {
    x[i] <- "Urn 2"
    z <- sample(uni_01, 1)
    if(z < 1/2)
      y[i] <- "White"
    else y[i] <- "Black"
  }
}
library(ggplot2)
ggplot(mapping = aes(x, fill = y)) + geom_bar(position = "dodge")
