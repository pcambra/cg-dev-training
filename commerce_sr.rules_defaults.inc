<?php
/**
 * @file
 * commerce_sr.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_sr_default_rules_configuration() {
  $rule = rules_reaction_rule();
  $rule->label = 'Create a Simple Recommendation Entity';
  $rule->requires = array(
    'rules',
    'commerce_sr',
    'commerce_cart',
  );
  $rule->event('commerce_cart_product_add');

  $rule->condition('user_has_role', array('account:select' => 'commerce-order:owner', 'roles' => array('2' => '2')));

  $rule->action('commerce_sr_create_entity', array('order:select' => 'commerce-order', 'product:select' => 'commerce-product'));

  $configs['rules_create_a_simple_recommendation_entity'] = $rule;

  return $configs;

}
