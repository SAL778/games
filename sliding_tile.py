
from random import shuffle

class Tile:

  def __init__(self,r,c):
    self.rows, self.cols = r, c
    assert(self.rows>=2 and self.cols>=2)
    self.state = []
    for j in range(r*c): self.state.append(j)
    shuffle(self.state)
    #random permutation for the state. Generated puzzle may not always be solvable.

    #Shifts indicate effect of moving the blank
    self.LF, self.RT, self.UP, self.DN = -1, 1, -self.cols, self.cols
    self.shifts = [self.LF, self.RT, self.UP, self.DN]

  def coord(self,x): return x // self.cols, x % self.cols

  def legal_shifts(self,psn):
    S = []
    c,r = psn % self.cols, psn // self.cols
    if c > 0:           S.append(self.LF)
    if c < self.cols-1: S.append(self.RT)
    if r > 0:           S.append(self.UP)
    if r < self.rows-1: S.append(self.DN)
    return S

  def slide(self,shift):
    # Sliding tiles from the perspective of the blank
    b_dx = self.state.index(0)
    o_dx = b_dx + shift
    self.state[b_dx], self.state[o_dx] = self.state[o_dx], self.state[b_dx]

  def showpretty(self):
    count, outstring = 0, ''
    for x in self.state:
      count += 1
      if x==0: outstring   += '   '
      elif x<10: outstring += ' ' + str(x) + ' '
      else: outstring      +=       str(x) + ' '
      if count%self.cols == 0: outstring += '\n'
    print('\n'+outstring)


cmd_left = 'a'
cmd_right = 'd'
cmd_up = 'w'
cmd_down = 's'
cmd_quit = ' '
cmd_chars = cmd_left + cmd_right + cmd_up + cmd_down + cmd_quit

def get_dimensions():
  instr = input('Enter rows x columns (e.g. 3 2): ')
  return int(instr.split()[0]), int(instr.split()[1])

def get_command():
  while True:
    sl = input('spacebar to quit, slide  < > ^ v  '
       + cmd_left + ' '
       + cmd_right + ' '
       + cmd_up + ' '
       + cmd_down + ' ')
    if len(sl)==0: return '\n'
    if sl[0] in cmd_chars: break
    print('Invalid character, try again')
  return sl[0]

def play():
  r,c = get_dimensions()
  st = Tile(r,c)
  st.showpretty()
  while True:
    ndx0 = st.state.index(min(st.state))
    ch = get_command()
    if ch == cmd_quit:
      print('\nBye! :) \n')
      return
    if ch == cmd_left: # Tile goes left, blank goes right
      if st.RT in st.legal_shifts(ndx0): st.slide(st.RT)
      else: print('Illegal shift')
    elif ch== cmd_right: # Tile goes right, blank goes left
      if st.LF in st.legal_shifts(ndx0): st.slide(st.LF)
      else: print('Illegal shift')
    elif ch== cmd_up: # Tile goes up, blank goes down
      if st.DN in st.legal_shifts(ndx0): st.slide(st.DN)
      else: print('Illegal shift')
    elif ch== cmd_down: # Tile goes down, blank goes up
      if st.UP in st.legal_shifts(ndx0): st.slide(st.UP)
      else: print('Illegal shift')
    st.showpretty()

play()

#check_win() function pending
