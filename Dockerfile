# Parent image from debian distribution
FROM debian:stable-slim

# Upgrade system and package manager
RUN apt-get update -y && apt-get upgrade -y

# Install tools for C++
RUN apt-get install -y cmake ninja-build build-essential

# Copy source code here  || Could be a git clone !
COPY . SoftEng2025Docker

# /!\ If done on a pc where the project has already been built then the build directory already exist !
# /!\ This will cause errors. To correct it you need to either delete the original build folder 
# /!\ Or change the name of the "build" folder you are creating in the container => what I did here with "Dbuild".

# Create building directory
RUN mkdir SoftEng2025Docker/Dbuild

# Configure and build
RUN cd SoftEng2025Docker/Dbuild && cmake -G "Ninja" .. && ninja && ninja install

# Clean to keep image small
RUN rm -rf SoftEng2025Docker && apt-get purge -y cmake ninja-build

# BE CAREFUL WITH THE -rf as it means "recurssive forced". 
#As an option for rm ("remove") it will forcibly remove without asking for permission all files and/or folders from the pc.
#SO DON'T USE rm -rf * |particularly SUDO rm -rf * => those wil respectively delete your hardrive and your whole computer.

# Tada
CMD HelloWorld