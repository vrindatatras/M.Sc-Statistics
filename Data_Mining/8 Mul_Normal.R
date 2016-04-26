rm(list=ls())
if(!require(plot3D, MASS)){
  install.packages("plot3D")
  install.packages("MASS")
}
set.seed(1)
mu <- matrix(c(9, 2), nrow=2, ncol=1)
sigma <- matrix(c(8, 2.3, 2.3, 5), nrow=2, ncol=2)

u <- svd(sigma)$u
eig <- diag(eigen(sigma)$values, 2)

z <- matrix(c(rnorm(1000, 0, 1), rnorm(1000, 0, 1)), nrow=2)
a <- u %*% t(eig^0.5) %*% u
b <- a %*% z

b[1,] <- b[1,] + 9
b[2,] <- b[2,] + 2

library(plot3D)
library(MASS)
a <- kde2d(b[1,],b[2,])
hist3D(z=a$z, main="3-D histogram")

mean(b[1, ])
mean(b[2, ])
var(b[1, ])
var(b[2, ])
cov(b[1, ], b[2, ])