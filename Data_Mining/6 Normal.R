if(!require(ggplot2))
  install.packages("ggplot2")

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

norm_01 <- rand_snormal(1000)
norm <- norm_01*sqrt(3) + 7

library(ggplot2)
p <- ggplot(mapping = aes(x = norm)) 
p <- p + geom_histogram(aes(y=..density..), binwidth = 1, colour="black", fill="gray75")
p <- p + stat_function(fun=dnorm, args = list(mean=7, sd=sqrt(3)), col = 'black', lwd=1.2)
p + xlab("Normal[7, 3]") + ylab("Density") + ggtitle("Histogram")

q <- ggplot(mapping = aes(sample = norm_01)) 
q + stat_qq(distribution = stats::qnorm) + ggtitle("Q - Q Plot")

breaks <- seq(min(norm), max(norm), length = 6)
intervals <- cut(norm, breaks, right=FALSE)
observed <- table(intervals)
prob <- c()
for(i in 1:5)
  prob[i] <- pnorm(breaks[i+1], 7, sqrt(3)) - pnorm(breaks[i], 7, sqrt(3))
expected <- prob*1000
chisq.test(cbind(observed, expected))

ks.test(norm, "pnorm", mean=7, sd=sqrt(3))

mean(norm)
var(norm)