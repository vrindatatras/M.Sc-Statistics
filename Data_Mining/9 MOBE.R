rm(list=ls())
set.seed(123)

MOBE <- function(n, l1, l2, l3){
  uni_01 <- runif(n)
  uni_02 <- runif(n)
  uni_03 <- runif(n)
  
  x1 <- -log(uni_01)/l1
  x2 <- -log(uni_02)/l2
  x3 <- -log(uni_03)/l3
  
  y1 <- c()
  y2 <- c()
  for(i in 1:1000){
    y1[i] <- min(x1[i], x3[i])
    y2[i] <- min(x2[i], x3[i])
  }
  y <- rbind(y1, y2)
  return(y)
}

y <- MOBE(1000, 5, 5, 2)

sum(y[1, ] < y[2,])
sum(y[1, ] > y[2,])
sum(y[1, ] == y[2, ])