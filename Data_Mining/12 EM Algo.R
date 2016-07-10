rm(list=ls())
set.seed(123)

rand_snormal <- function(n){
  uni_01 <- runif(2*n)
  y1 <- uni_01[1:n]
  y2 <- uni_01[n+1:1000]
  y <- c(y1, y2)
  x <- c()
  for(i in 1:n){        # Random number from double exponential(1)
    x[i] <- -log(1-y1[i])
    x[n +i] <- log(1-y2[i])
  }
  
  p <- c()
  i<-1
  while(length(p) < 1000){    # Acceptance/Rejection condition
    U = sample(uni_01, 1)
    z = sample(x, 1)
    if(exp(-abs(z))*1.315*U/2 <= dnorm(z, 0, 1)){
      p[i] <- z
      i <- i+1
    }
    else i <- i-1
  }
  return(p)
}

rn1 <- rand_snormal(1000)*sqrt(2) + 3
c(mean(rn1), var(rn1))
rn2 <- rand_snormal(1000)*sqrt(3) + 10
c(mean(rn2), var(rn2))

x <- c(sample(rn1, 400), sample(rn2, 600))
p <- 0.4
m1 <- 6
m2 <- 18
v1 <- 4
v2 <- 8
d <- rep(1, 5)
a <- 0.00001
i <- 0
while(sum(d > a) > 0){
  d1 <- c(p, m1, m2, v1, v2)
  delta <- (dnorm(x, m2, sqrt(v2))*(1-p))/(dnorm(x, m1, sqrt(v2))*p + dnorm(x, m2, sqrt(v2))*(1-p))
  p <- sum(1 - delta)/1000
  m1 <- sum((1-delta)*x)/sum(1-delta)
  m2 <- sum((delta)*x)/sum(delta)
  v1 <- sum((1-delta)*(x-m1)^2)/sum(1-delta)
  v2 <- sum((delta)*(x-m2)^2)/sum(delta)
  d2 <- c(p, m1, m2, v1, v2)
  d <- abs(d2 - d1)
  d1 <- d2
  i <- i+1
}
# Number of iterations performed:
i
# Parameter estimates are:
d1
