# Random number generation from Gamma(alpha) distribution
if(!require(ggplot2))
  install.packages("ggplot2")

rm(list=ls())
set.seed(1234)

uni_01 <- runif(2000, 0, 1)  # Random number from U[0, 1]
y <- -log(uni_01)           # Random number from exp(1)

z <- c()
for(i in 1:2000)
  z[i] <- sum(sample(y, 5))     # Random number from gamma(5)

rand_gamma <- function(n, alpha){             # Random number from gamma(alpha); 0<alpha<1
  c <- (1/alpha + 1/exp(1))/gamma(alpha)
  x <- c()
  for(i in 1:(2*n)){
    if(uni_01[i] < 1/(c*gamma(1 + alpha)))
      x[i] <- (uni_01[i]*c*gamma(1 + alpha))^(1/alpha)
    else if(uni_01[i] > 1/(c*gamma(1 + alpha)))
      x[i] <- -log((1/(c*gamma(1 + alpha))-uni_01[i])*c*gamma(alpha) + 1/exp(1))
  }
  x <- na.omit(x)
  
  i <- 1
  p<-c()
  while(length(p) < n){
    u <- sample(uni_01, 1)
    if(x[i] < 1){
      if(u*(x[i]^-0.2)/gamma(alpha) < dgamma(x[i], shape=alpha)){
        p[i] <- x[i]
        i <- i + 1
      }  
      else i <- i - 1
    }
    else if(x[i] > 1){
      if(u*(exp(-x[i]))/gamma(alpha) < dgamma(x[i], shape=alpha)){
        p[i] <- x[i]
        i <- i + 1
      }
      else i <- i - 1
    }
  }
  return(p)
}
gam <- rand_gamma(1000, 0.8)

gam <- gam + z

library(ggplot2)
p <- ggplot(mapping = aes(x = gam)) 
p <- p + geom_histogram(aes(y=..density..), binwidth = 0.9, colour="black", fill="gray75")
p <- p + stat_function(fun=dgamma, args = list(shape=5.8), col = 'black', lwd=1.2)
p + xlab("Gamma(7.8)") + ylab("Density") + ggtitle("Histogram")

q <- ggplot(mapping = aes(sample = gam))+ ggtitle("Q - Q Plot")
q + stat_qq(distribution = stats::qgamma, dparams = list(shape=5.8))

breaks <- seq(0, max(gam), length = 6)
intervals <- cut(gam, breaks, right=FALSE)
observed <- table(intervals)
prob <- c()
for(i in 1:5)
  prob[i] <- pgamma(breaks[i+1], 5.8) - pgamma(breaks[i], 5.8)
expected <- prob*1000
chisq.test(cbind(observed, expected))

ks.test(gam, "pgamma", shape=5.8)

mean(gam)
var(gam)
