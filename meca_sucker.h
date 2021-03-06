#ifndef MECA_SUCKER_H
#define MECA_SUCKER_H

typedef enum
{
  MECA_SUCKER_LEFT,
  MECA_SUCKER_RIGHT,
} meca_sucker_id_t;

typedef enum
{
  MECA_SUCKER_CLOSE,
  MECA_SUCKER_OPEN,
  MECA_SUCKER_PUMP,
  MECA_SUCKER_DISABLE,
} meca_sucker_state_t;

void meca_sucker_init(void);
void meca_sucker_set_state(meca_sucker_id_t id, meca_sucker_state_t state);
void meca_sucker_disable(void);
int meca_sucker_console_handler(const char * command);

#endif// MECA_SUCKER_H
