<dl class="MarkupActivityLog">
	<?php foreach ($entries as $entry):?>
		<?php if ($entry->date):?>
			<dt class="date-stamp"><i class="fa fa-calendar"></i> <?php echo $entry->date;?></dt>
			<dd class="date-stamp">&nbsp;</dd>
		<? endif; ?>
		<dt><i class="fa fa-clock-o"></i> <?php echo $entry->time;?><br><?php echo __("by ");?><?php echo $entry->user_fields;?></dt>
		<dd>
			<ul>				
				<?php foreach ($entry->changes as $change):?>
				<li>
					<?php echo __("Changed ");?> <b><?php echo $change->field ;?></b>
					<?php if ($change->type == 'FieldtypeTextarea'):?>
						<a href="<?php echo $config->urls->admin;?>activity-log-service/<?php echo $change->attrs; ?>" class="view-diff"><?php echo __('View Changes');?></a>
					<? else: ?>
						<?php echo __("from ");?> <del class='diffmod<?php if (!$change->old) echo ' null'?>'><?php echo $change->old? $change->old:'null'?></del>
						<?php echo __("to ");?> <ins class='diffmod<?php if (!$change->new) echo ' null'?>'><?php echo $change->new? $change->new:'null'?></ins>
					<? endif; ?>
				</li>
				<? endforeach; ?>
				
			</ul>
		</dd>
	<? endforeach; ?>
</dl>