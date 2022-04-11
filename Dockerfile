FROM --platform=linux/arm64 golang:1.15
WORKDIR /go/src
ADD ./src /go/src
