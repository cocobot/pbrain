# Makefile for configuring and building an AUSBEE project
#
#Set ausbee directory path. Can be relative or absolute
AUSBEE_DIR=../../ausbee

#Get project name
PROJECT_NAME=$(notdir $(patsubst i%/,%,$(lastword $(CURDIR))))

#List all source files
PROJECT_LOCAL_SRC_FILES=$(wildcard *.c)

#Include main Makefile
include $(AUSBEE_DIR)/ausbee.mk
