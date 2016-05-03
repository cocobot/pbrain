#include <cocobot.h>
#include "strat_hut.h"

#define STRAT_HUT_VIOLET        0
#define STRAT_HUT_GREEN         1



static unsigned int strat_hut_get_score(int hut)
{
  (void)hut; //each hut is equal

  return 10;
}

static float strat_hut_get_x(int hut)
{
  switch(hut)
  {
    case STRAT_HUT_VIOLET:
      return -1075;

    case STRAT_HUT_GREEN:
      return 1075;
  }

  return 10000; //unvalid hut has been requested.
}

static float strat_hut_get_y(int hut)
{
  (void)hut; //each hut is equal
  return 700;
}

static float strat_hut_get_a(int hut)
{
  (void)hut; //each hut is equal
  return -90; //we want to hit the door with our back
}

static float strat_hut_get_exec_time(int hut)
{
  (void)hut; //each hut is equal
  return 1000; //in ms
}

static float strat_hut_get_success_proba(int hut)
{
  (void)hut; //each hut is equal

  return 0.99;
}

static cocobot_action_callback_result_t strat_hut_action(void * arg)
{
  (void)arg; //each hut is equal

  cocobot_trajectory_set_opponent_detection(0);
  cocobot_trajectory_goto_d(-10400, 1000);
  cocobot_trajectory_wait();
  cocobot_trajectory_set_opponent_detection(1);

  cocobot_trajectory_goto_d(300, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  cocobot_trajectory_wait();


  return COCOBOT_RETURN_ACTION_SUCCESS;
}

static cocobot_action_callback_result_t strat_hut_preexec(void * arg)
{
  (void)arg;

  cocobot_trajetory_set_xy_default(COCOBOT_TRAJECTORY_BACKWARD);

  return COCOBOT_RETURN_ACTION_SUCCESS;
}

static cocobot_action_callback_result_t strat_hut_cleanup(void * arg)
{
  (void)arg;

  cocobot_trajetory_set_xy_default(COCOBOT_TRAJECTORY_FORWARD);
  
  return COCOBOT_RETURN_ACTION_SUCCESS;
}

void strat_hut_register(void)
{
  if(cocobot_game_state_get_color() == COCOBOT_GAME_STATE_COLOR_NEG)
  {
    cocobot_action_scheduler_add_action(
                                        "hut_violet",
                                        strat_hut_get_score(STRAT_HUT_VIOLET),
                                        strat_hut_get_x(STRAT_HUT_VIOLET),
                                        strat_hut_get_y(STRAT_HUT_VIOLET),
                                        strat_hut_get_a(STRAT_HUT_VIOLET),
                                        strat_hut_get_exec_time(STRAT_HUT_VIOLET),
                                        strat_hut_get_success_proba(STRAT_HUT_VIOLET),
                                        strat_hut_preexec,
                                        strat_hut_action,
                                        strat_hut_cleanup,
                                        (void *)STRAT_HUT_VIOLET,
                                        NULL);
  }

  if(cocobot_game_state_get_color() == COCOBOT_GAME_STATE_COLOR_POS)
  {
    cocobot_action_scheduler_add_action(
                                        "hut_green",
                                        strat_hut_get_score(STRAT_HUT_GREEN),
                                        strat_hut_get_x(STRAT_HUT_GREEN),
                                        strat_hut_get_y(STRAT_HUT_GREEN),
                                        strat_hut_get_a(STRAT_HUT_GREEN),
                                        strat_hut_get_exec_time(STRAT_HUT_GREEN),
                                        strat_hut_get_success_proba(STRAT_HUT_GREEN),
                                        strat_hut_preexec,
                                        strat_hut_action,
                                        strat_hut_cleanup,
                                        (void *)STRAT_HUT_GREEN,
                                        NULL);
  }
}
