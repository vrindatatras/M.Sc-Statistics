# Random Number generation through LCG (Uniform Distribution)
if(!require(ggplot2))
  install.packages("ggplot2")

rm(list=ls())
LGC <- function(a, c, M, n, y){
  x <- c()
  x[1] <- y
  for(i in 1:n)
    x[i+1] <- (a*x[i]+c) %% (M)
  return(x[-1]/M)
}

uni_01 <- LGC(a= 23, c= 0, M= 10^8, n= 1000, y= 123)

library(ggplot2)
p <- ggplot(mapping = aes(x = uni_01)) 
p <- p + geom_histogram(aes(y=..density..), binwidth = .09, colour="black", fill="gray75")
p <- p + stat_function(fun=dunif, args = list(min=0, max=1), col = 'black', lwd=1.2)
p + xlab("Uniform[0, 1]") + ylab("Density") + ggtitle("Histogram") + xlim(0,1)

q <- ggplot(mapping = aes(sample = uni_01)) + ggtitle("Q-Q Plot")
q + stat_qq(distribution = stats::qunif) 


breaks <- seq(0, 1, length = 6)
intervals <- cut(uni_01, breaks, right=FALSE)
observed <- table(intervals)
prob <- c()
for(i in 1:5)
  prob[i] <- punif(breaks[i+1], 0, 1) - punif(breaks[i], 0, 1)
expected <- prob*1000
chisq.test(cbind(observed, expected))

ks.test(uni_01, "punif", 0, 1)
