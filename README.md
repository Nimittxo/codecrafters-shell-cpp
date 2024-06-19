[![progress-banner](https://backend.codecrafters.io/progress/shell/6242b4b0-02af-4dc3-8a01-b7980b2096fa)](https://app.codecrafters.io/users/codecrafters-bot?r=2qF)

Here I created and completed my first codecrafter challenge:
["Build Your Own Shell" Challenge](https://app.codecrafters.io/courses/shell/overview).

In this challenge, I built my own POSIX compliant shell that's capable of
interpreting shell commands, running external programs and builtin commands like
cd, pwd, echo and more. Along the way, I'll learn about shell command parsing,
REPLs, builtin commands, and more.

**Note**: If you're viewing this repo on GitHub, head over to
[codecrafters.io](https://codecrafters.io) to try the challenge.

# Versions

**Version 1.0.0**
- Initial release
- Features:
  - POSIX compliant shell
  - Interpretation of basic shell commands
  - Execution of external programs
  - Builtin commands: `cd`, `pwd`, `echo`, `clear`, `ls`, `cat`
  - ANSI escape code support for `clear` command

# Passing the first stage

The entry point for your `shell` implementation is in `src/main.cpp`. Study and
uncomment the relevant code, and push your changes to pass the first stage:

```sh
git add .
git commit -m "pass 1st stage" # any msg
git push origin master
