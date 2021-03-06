LGC <- function(a, c, M, n, y){
  a=23
  c=0
  x <- rep(0, n)
  x[1] <- y
  for(i in 1:n)
    x[i+1] <- (a*x[i]+c) %% (M)
  return(x/M)
}

uni_01 <- LGC(23, 0, 10^8, 1000, 123)

lambda <- 5
x <- rep(0, 1000)
for(i in 1:1000){
  x[i] <- -log(uni_01[i])/lambda
}

mean(x)
var(x)