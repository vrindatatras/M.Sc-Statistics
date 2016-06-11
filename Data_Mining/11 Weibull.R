if(!require(ggplot2))
  install.packages("ggplot2")

rm(list=ls())
set.seed(123)

rand_web <- function(n, alpha, lambda){
  webu <- (-log(runif(n))/lambda)^(1/alpha)
}

webu <- rand_web(1000, 7, 3)

library(ggplot2)
p <- ggplot(mapping = aes(x = webu)) 
p <- p + geom_histogram(aes(y=..density..), binwidth = .07, colour="black", fill="gray75")
p <- p + stat_function(fun=dweibull, args = list(shape=7, scale=1/3^(1/7)), col = 'black', lwd=1.2)
p + xlab("Weibull(7, 3)") + ylab("Density") + ggtitle("Histogram")

q <- ggplot(mapping = aes(sample = webu)) + ggtitle("Q - Q Plot")
q + stat_qq(distribution = stats::qweibull, dparams = list(shape=7))

breaks <- seq(min(webu), max(webu), length = 6)
intervals <- cut(webu, breaks, right=FALSE)
observed <- table(intervals)
prob <- c()
for(i in 1:5)
  prob[i] <- pweibull(breaks[i+1], 7, 1/3^(1/7)) - pweibull(breaks[i], 7, 1/3^(1/7))
expected <- prob*1000
chisq.test(cbind(observed, expected))

ks.test(webu, "pweibull", 7, 1/3^(1/7))

al <- 8         # Initial guess for the parameter
d <- 1
n <- 1000
while(d > 0.00001){
  ao <- al
  h1 <- n/al-(n/sum(webu^al))*sum(webu^al*log(webu)) + sum(log(webu)) 
  h2 <- -(n/al^2) - n*(sum((webu^al)*log(webu)^2)/sum(webu^al))+n*sum((webu^al)*log(webu))^2/(sum(webu^al))^2
  al <- ao - h1/h2
  d <- abs(al - ao)
}

alpha_hat <- al
alpha_hat
lambda_hat <- n/sum(webu^alpha_hat)
lambda_hat
