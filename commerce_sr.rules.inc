<?php
/**
 * @file
 *   commerce_sr.rules.inc
 * Rules integrations for Commerce SR
 */

/**
 * Impliments hook_rules_action_info().
 */
function commerce_sr_rules_action_info() {
  $actions = array();

  $actions['commerce_sr_create_entity'] = array(
    'label' => t('Create a SR entity'),
    'parameter' => array(
      'order' => array(
        'type' => 'commerce_order',
        'label' => t('Order'),
      ),
      'product' => array(
        'type' => 'commerce_product',
        'label' => t('Product'),
      ),
    ),
    'group' => t('Commerce SR'),
    'callbacks' => array(
      'execute' => 'commerce_sr_create_entity',
    ),
  );

  return $actions;
}

/**
 * Rule callback.
 */
function commerce_sr_create_entity($order, $product) {
  $rec = entity_create('recommendation', array(
    'type' => 'recommendation',
    'uid' => $order->order_id,
    'product_id' => $product->product_id,
    'recommendation_price' => $product->commerce_price,
    'date' => time(),
  ));
  $rec->save();
}
