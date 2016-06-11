rm(list=ls())
set.seed(123)

BBBE <- function(n, l1, l2, l3){
  uni_01 <- runif(n)
  uni_02 <- runif(n)
  uni_03 <- runif(n)
  
  x1 <- -log(uni_01)/l1
  x2 <- -log(uni_02)/l2
  x3 <- -log(uni_03)/l3
  
  y1 <- c()
  y2 <- c()
  i <- 1
  while(length(y1) < n){
    y1[i] <- min(sample(x1, 1), sample(x3, 1))
    y2[i] <- min(sample(x2, 1), sample(x3, 1))
    if(y1[i] == y2[i])
      i <- i - 1
    else i <- i + 1
  }
  y <- rbind(y1, y2)
  return(y)
}

y <- BBBE(1000, 5, 5, 2)
sum(y[1, ] < y[2,])
sum(y[1, ] > y[2,])
sum(y[1, ] == y[2, ])