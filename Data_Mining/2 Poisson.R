# Non-Uniform Random Number Generation (Poisson Distribution)
# Generating Random Number from Uniform(0, 1)
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

# Calculating Cumulative SUm
cumpoi <- rep(0, 1000)
for(i in 1:1000){
  cumpoi[1] <- dpois(x = 0, lambda = 5)
  a <- dpois(x = i+1, lambda = 5)
  cumpoi[i+1] <- cumpoi[i] + a
  if(cumpoi[i+1] == 0) break
}

# Generating from Poisson Distribution
b <- rep(0, 1000)
for(i in 1:1000){
  for(j in 1:1000)
    if(uni_01[i] > cumpoi[j])
      b[i] <- j+1
}

mean(b[b<100])
var(b[b<100])