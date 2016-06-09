# Random number generation from Double exponential(Laplace) distribution:

rm(list=ls())
LGC <- function(a, c, M, n, y){
  x <- rep(0, n)
  x[1] <- y
  for(i in 1:n)
    x[i+1] <- (a*x[i]+c) %% (M)
  return(x/M)
}
uni_01 <- LGC(23, 0, 10^8, 1000, 123)

x <- rep(0, 1000)
y1 <- uni_01[1:500]
y2 <- uni_01[501:1000]
y <- c(y1, y2)

for(i in 1:500){
    x[i] <- -log(1-y1[i])
    x[500 +i] <- log(1-y2[i])
}

hist(x)